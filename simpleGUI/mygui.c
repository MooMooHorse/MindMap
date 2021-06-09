#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include <time.h>

// #include "imgui.h"
#include "mygui.h"
#include "Output.h"
#include "ButtonRelated.h"


#if !defined(KMOD_SHIFT)
#define KMOD_SHIFT 0x01
#define KMOD_CTRL  0x02
#endif

/* 鼠标和空间状态 */
typedef struct {
	double mousex;
	double mousey;
	int    mousedown;
	int    clickedItem;// item that was clicked
	int    actingMenu; // acting menu list 
	int    kbdItem;    // item that takes keyboard
	int    lastItem;   // item that had focus just before
	int    keyPress;   // input key
	int    charInput;  // input char
	int    keyModifiers;  //  key modifier (shift, ctrl)
} UIState;

static UIState gs_UIState;
static double  gs_menuRect[4];
static int ESCC=0;

/* 测试：坐标点(x,y)是否位于包围和 [x1,x2] X [y1,y2] 内部 */
static bool inBox(double x, double y, double x1, double x2, double y1, double y2)
{
	return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}

static bool notInMenu(double x, double y)
{
	return ! inBox(x, y, gs_menuRect[0], gs_menuRect[1], gs_menuRect[2], gs_menuRect[3]);
}

static void setMenuRect(double x1, double x2, double y1, double y2)
{
	gs_menuRect[0] = x1;
	gs_menuRect[1] = x2;
	gs_menuRect[2] = y1;
	gs_menuRect[3] = y2;
}


static void mySetPenColor(char *color)
{
	if( color && strlen(color)>0 ) SetPenColor(color);
}
/* 
 *  libgraphics 预定义的颜色名称
 *
 *  DefineColor("Black", 0, 0, 0);
 *  DefineColor("Dark Gray", .35, .35, .35);
 *  DefineColor("Gray", .6, .6, .6);
 *  DefineColor("Light Gray", .75, .75, .75);
 *  DefineColor("White", 1, 1, 1);
 *  DefineColor("Brown", .35, .20, .05);
 *  DefineColor("Red", 1, 0, 0);
 *  DefineColor("Orange", 1, .40, .1);
 *  DefineColor("Yellow", 1, 1, 0);
 *  DefineColor("Green", 0, 1, 0);
 *  DefineColor("Blue", 0, 0, 1);
 *  DefineColor("Violet", .93, .5, .93);
 *  DefineColor("Magenta", 1, 0, 1);
 *  DefineColor("Cyan", 0, 1, 1);
 */

/* 
 *  菜单颜色
 */
static struct {
	char frame[32];
	char label[32];
	char hotFrame[32];
	char hotLabel[32];
	int  fillflag;
} gs_predefined_colors[] = {
	{"Blue",      "Blue",	"Red",	    "Red",   0 }, // 
	{"Orange",    "Black", "Green",    "Blue",  0 }, // 
	{"Orange",    "White", "Green",    "Blue",  1 }, // 填充
	{"Light Gray","Black",  "Dark Gray","Blue",0 },  // 
	{"Light Gray","Black",  "Dark Gray","Yellow",1 },  // 填充
	{"Brown",     "Red",    "Orange",   "Blue",0 },
	{"Brown",     "Red",    "Orange",   "White",1 }   // 填充
},

gs_menu_color = {
	"Blue",      "Blue",	"Red",	    "Red",   0 , // 不填充
},

gs_button_color = {
	"Blue",      "Blue",	"Red",	    "Red",   0 , // 不填充
},

gs_textbox_color = {
	"Blue",      "Blue",	"Red",	    "Red",   0 , // 不填充
};

void MysetButtonColors(char *frame, char*label, char *hotFrame, char *hotLabel, int fillflag)
{
	if(frame) strcpy(gs_button_color.frame, frame);
	if(label) strcpy(gs_button_color.label, label);
	if(hotFrame) strcpy(gs_button_color.hotFrame, hotFrame);
	if(hotLabel) strcpy(gs_button_color.hotLabel ,hotLabel);
	gs_button_color.fillflag = fillflag;
}

void MysetMenuColors(char *frame, char*label, char *hotFrame, char *hotLabel, int fillflag)
{
	if(frame) strcpy(gs_menu_color.frame, frame);
	if(label) strcpy(gs_menu_color.label, label);
	if(hotFrame) strcpy(gs_menu_color.hotFrame, hotFrame);
	if(hotLabel) strcpy(gs_menu_color.hotLabel ,hotLabel);
	gs_menu_color.fillflag = fillflag;
}

void MysetTextBoxColors(char *frame, char*label, char *hotFrame, char *hotLabel, int fillflag)
{
	if(frame) strcpy(gs_textbox_color.frame, frame);
	if(label) strcpy(gs_textbox_color.label, label);
	if(hotFrame) strcpy(gs_textbox_color.hotFrame, hotFrame);
	if(hotLabel) strcpy(gs_textbox_color.hotLabel ,hotLabel);
	gs_textbox_color.fillflag = fillflag;
}

void MyusePredefinedColors(int k)
{
	int N = sizeof(gs_predefined_colors)/sizeof(gs_predefined_colors[0]);
	gs_menu_color    = gs_predefined_colors[k%N];
	gs_button_color  = gs_predefined_colors[k%N];
	gs_textbox_color = gs_predefined_colors[k%N];
}
void MyusePredefinedButtonColors(int k)
{
	int N = sizeof(gs_predefined_colors)/sizeof(gs_predefined_colors[0]);
	gs_button_color  = gs_predefined_colors[k%N];
}
void MyusePredefinedMenuColors(int k)
{
	int N = sizeof(gs_predefined_colors)/sizeof(gs_predefined_colors[0]);
	gs_menu_color    = gs_predefined_colors[k%N];
}
void MyusePredefinedTexBoxColors(int k)
{
	int N = sizeof(gs_predefined_colors)/sizeof(gs_predefined_colors[0]);
	gs_textbox_color = gs_predefined_colors[k%N];
}

/* 函数名：	InitGUI
 *
 * 功能：初始化工作
 *
 * 用法：在窗口创建或字体设置之后调用
 */
void MyInitGUI()
{
	memset(&gs_UIState, 0, sizeof(gs_UIState));
}

/* 调用该函数,得到鼠标的状态 */
void MyuiGetMouse(int x, int y, int button, int event)
{
	 gs_UIState.mousex = ScaleXInches(x);/*pixels --> inches*/
	 gs_UIState.mousey = ScaleYInches(y);/*pixels --> inches*/

	 switch (event) {
	 case BUTTON_DOWN:
		 gs_UIState.mousedown = 1;
		 break;
	 case BUTTON_UP:
		 gs_UIState.mousedown = 0;
		 break;
	 }
}



/* 调用该函数,得到键盘的输入 */
void MyuiGetKeyboard(int key, int event)
{
	if( event==KEY_DOWN ) 
	{
		switch (key ) 
		{
			case VK_SHIFT:
				gs_UIState.keyModifiers |= KMOD_SHIFT;
				break;
			case VK_CONTROL:
				gs_UIState.keyModifiers |= KMOD_CTRL;
				break;
			case VK_ESCAPE:
				ESCC=1;
			break;
			default:
				gs_UIState.keyPress = key;
		}
	} 
	else if( event==KEY_UP )
	{
		switch (key ) 
		{
			case VK_SHIFT:
				gs_UIState.keyModifiers &= ~KMOD_SHIFT;
				break;
			case VK_CONTROL:
				gs_UIState.keyModifiers &= ~KMOD_CTRL;
				break;
			case VK_ESCAPE:
				ESCC=0;
			break;
			default:
				gs_UIState.keyPress = 0;
		}
	}
}

/* 调用该函数,得到文本输入 */
void MyuiGetChar(int ch)
{
	gs_UIState.charInput = ch;
}


/* 
 * 函数名：button
 *
 * 功能：显示一个按钮（button）
 *
 * 用法：if( button(GenUUID(0),x,y,w,h,label) ) {
 *           执行语句，响应用户按下该按钮
 *       }
 *
 *   id  - 唯一号
 *   x,y - 位置
 *   w,h - 宽度和高度
 *   label - 按钮上的文字标签
 *
 * 返回值
 *   0 - 用户没有点击（按下并释放）按钮  
 *   1 - 点击了按钮
 */
int Mybutton(int id, double x, double y, double w, double h, char *label)
{
	char * frameColor = gs_button_color.frame;
	char * labelColor = gs_button_color.label;
	double movement = 0.2*h;
	double shrink = 0.15*h;
	double sinkx = 0, sinky = 0;
	//int isHotItem = 0;

	if (notInMenu(gs_UIState.mousex, gs_UIState.mousey) &&
		inBox(gs_UIState.mousex, gs_UIState.mousey, x, x + w, y, y + h)) 
	{
		static int timesss = 0; timesss++;
		//printf("%d not in %f %f %f %f\n", timesss, gs_menuRect[0], gs_menuRect[1], gs_menuRect[2], gs_menuRect[3]);
		frameColor = gs_button_color.hotFrame;
		labelColor = gs_button_color.hotLabel;
		gs_UIState.actingMenu = 0; // menu lose focus
		if ( gs_UIState.mousedown) {
			gs_UIState.clickedItem = id;
			sinkx =   movement;
			sinky = - movement;
		}
	}
	else {
		if ( gs_UIState.clickedItem==id )
			gs_UIState.clickedItem = 0;
	}

	// If no widget has keyboard focus, take it
	if (gs_UIState.kbdItem == 0)
		gs_UIState.kbdItem = id;
	// If we have keyboard focus, we'll need to process the keys
	if ( gs_UIState.kbdItem == id && gs_UIState.keyPress==VK_TAB ) 
	{
		// If tab is pressed, lose keyboard focus.
		// Next widget will grab the focus.
		gs_UIState.kbdItem = 0;
		// If shift was also pressed, we want to move focus
		// to the previous widget instead.
		if ( gs_UIState.keyModifiers & KMOD_SHIFT )
			gs_UIState.kbdItem = gs_UIState.lastItem;
		gs_UIState.keyPress = 0;
	}
	gs_UIState.lastItem = id;

	// draw the button
	mySetPenColor(frameColor);
	MydrawBox(x+sinkx, y+sinky, w, h, gs_button_color.fillflag,
		label, 'C', labelColor);
	if( gs_button_color.fillflag ) {
		mySetPenColor( labelColor );
		MydrawRectangle(x+sinkx, y+sinky, w, h, 0,1);
	}

	// 画键盘提示, show a small ractangle frane
	if( gs_UIState.kbdItem == id ) {
		mySetPenColor( labelColor );
		MydrawRectangle(x+sinkx+shrink, y+sinky+shrink, w-2*shrink, h-2*shrink, 0,1);
	}

	if( gs_UIState.clickedItem==id && // must be clicked before
		! gs_UIState.mousedown )   // but now mouse button is up
	{
		gs_UIState.clickedItem = 0;
		gs_UIState.kbdItem = id;
		return 1; 
	}

	return 0;
}

/* 
 * 显示一个菜单项
 *   id  - 菜单项的唯一号
 *   x,y - 菜单项的位置
 *   w,h - 菜单项的大小
 *   label - 菜单项的标签文字
 *
 * 返回值
 *   0 - 用户没有点击（按下并释放）此菜单项  
 *   1 - 点击了此菜单项 
 */
static int menuItem(int id, double x, double y, double w, double h, char *label)
{
	char * frameColor = gs_menu_color.frame;
	char * labelColor = gs_menu_color.label;
	if (inBox(gs_UIState.mousex, gs_UIState.mousey, x, x + w, y, y + h)) {
		frameColor = gs_menu_color.hotFrame;
		labelColor = gs_menu_color.hotLabel;
		//if (gs_UIState.mousedown) {
		if ( (gs_UIState.clickedItem == id ||gs_UIState.clickedItem == 0) && gs_UIState.mousedown) {
			gs_UIState.clickedItem = id;
		}
	}
	else {
		if ( gs_UIState.clickedItem==id )
			gs_UIState.clickedItem = 0;
	}

	mySetPenColor(frameColor);
	MydrawBox(x, y, w, h, gs_menu_color.fillflag, label, 'L', labelColor);

	if( gs_UIState.clickedItem==id && // must be clicked before
		! gs_UIState.mousedown )     // but now mouse button is up
	{
		gs_UIState.clickedItem = 0;
		return 1; 
	}

	return 0;
}

/* 
 * 函数名：shortcutkey
 *
 * 功能：从菜单标签中提取“快捷键”大写字母
 *       要求快捷键标志 Ctrl-X 位于标签的结尾部分
 */
static char ToUpperLetter(char c)
{
	return (c>='a' && c<='z' ? c-'a'+'A' : c);
}

static char shortcutkey(char *s)
{
	char predStr[] = "Ctrl-";
	int M = strlen(predStr)+1;
	int n = s ? strlen(s) : 0;

	if( n<M || strncmp(s+n-M, predStr, M-1)!=0 )
		return 0;

	return ToUpperLetter(s[n-1]);
}

/* 
 * 函数名：menuList
 *
 * 功能：显示一个组菜单
 *
 * 用法：choice = menuList(GenUUID(0),x,y,w,h,labels,n);
 *
 *   id  - 菜单的唯一号
 *   x,y,w,h - 菜单类别的位置和大小
 *   wlist,h - 菜单列表的宽度和高度
 *   labels[] - 标签文字，[0]是菜单类别，[1...n-1]是菜单列表
 *   n   - 菜单项的个数
 *
 * 返回值
 *   -1    - 用户没有点击（按下并释放）按钮  
 *   >=0   - 用户选中的菜单项 index （在labels[]中）
 *
 */
int MymenuList(int id, double x, double y, double w, double wlist, double h, char *labels[], int n)
{
	static int unfoldMenu = 0;
	int result = 0;
	int k = -1;

	// 处理快捷键

	if( gs_UIState.keyModifiers & KMOD_CTRL ) {
		for( k=1; k<n; k++ ) {
			int kp = ToUpperLetter( gs_UIState.keyPress );
			if( kp && kp == shortcutkey(labels[k]) ) {
				gs_UIState.keyPress = 0;
				break;
			}
		}
	}

	if( k>0 && k<n ) 
	{	// 成功匹配快捷键
		unfoldMenu = 0;
		return k; 
	}

	// 处理鼠标

	if( inBox(gs_UIState.mousex, gs_UIState.mousey, x, x + w, y, y + h) )
		gs_UIState.actingMenu = id;

	if( menuItem(id, x, y, w, h, labels[0]) )
		unfoldMenu = ! unfoldMenu;

	if( gs_UIState.actingMenu == id && unfoldMenu  ) {
		int k;
		gs_UIState.charInput = 0; // disable text editing
		gs_UIState.keyPress = 0;  // disable text editing
		setMenuRect(x, x + wlist, y - n * h + h, y);
		for( k=1; k<n; k++ ) {
			if ( menuItem(GenUIID(k)+id, x, y-k*h, wlist, h, labels[k]) ) {
				unfoldMenu = 0;
				setMenuRect(0, 0, 0, 0);
				result = k;
			}
		}
	}
	return result;
}

void MydrawMenuBar(double x, double y, double w, double h)
{
	mySetPenColor(gs_menu_color.frame);
	MydrawRectangle(x,y,w,h,gs_menu_color.fillflag,1);
}


/* 
 * 函数名：textbox
 *
 * 功能：显示一个文本编辑框，显示和编辑文本字符串
 *
 * 用法：textbox(GenUUID(0),x,y,w,h,textbuf,buflen);
 *       或者
         if( textbox(GenUUID(0),x,y,w,h,textbuf,buflen) ) {
 *           文本字符串被编辑修改了，执行相应语句
 *       }
 *
 *   id  - 唯一号，一般用GenUUID(0), 或用GenUUID（k)（k是循环变量）
 *   x,y - 文本框位置
 *   w,h - 文本框的宽度和高度
 *   textbuf - 被编辑的文本字符串（以\0结尾）
 *   buflen - 可存储的文本字符串的最大长度
 * 返回值
 *   0 - 文本没有被编辑
 *   1 - 被编辑了
 */
int Mytextbox(int id, double x, double y, double w, double h, char textbuf[], int buflen,int Index,int Dep)
{
	char * frameColor = gs_textbox_color.frame;
	char * labelColor = gs_textbox_color.label;
	int textChanged = 0;
	int len = strlen(textbuf);
	double indent = GetFontAscent()/2;
	double textPosY = y+h/2-GetFontAscent()/2;

	if (notInMenu(gs_UIState.mousex, gs_UIState.mousey) &&
		inBox(gs_UIState.mousex, gs_UIState.mousey, x, x + w, y, y + h) ) 
	{
		frameColor = gs_textbox_color.hotFrame;
		labelColor = gs_textbox_color.hotLabel;
		gs_UIState.actingMenu = 0; // menu lose focus
		if ( gs_UIState.mousedown) {
			gs_UIState.clickedItem = id;
		}
	}

	// If no widget has keyboard focus, take it
	if (gs_UIState.kbdItem == 0)
		gs_UIState.kbdItem = id;

	if (gs_UIState.kbdItem == id)
		labelColor = gs_textbox_color.hotLabel;

	// Render the text box
	mySetPenColor(frameColor);
	
	MovePen(x, y);
	if( gs_textbox_color.fillflag ) StartFilledRegion(1); 
	{
		switch(Get_Mode()){
			case 0: 
	// printf("\nBlam!\n");
				mySetPenColor("White");
			break;
			case 1:
				mySetPenColor("Black");
			break;
		}
		DrawLine(0, h);
		DrawLine(w, 0);
		DrawLine(0, -h);
		DrawLine(-w, 0);
	}
	switch(Get_Mode()){
		case 0: 
			switch(Dep){
				case 0:
				mySetPenColor("Layer01Dark");
				break; 
				case 1:
				mySetPenColor("Layer02Dark");
				break;
				case 2:
				mySetPenColor("Layer03Dark");
				break;
				case 3:
				mySetPenColor("Layer04Dark");
				break;
			}
		break;
		case 1:
			switch(Dep){
				case 0:
				mySetPenColor("Layer04Dark");
				break; 
				case 1:
				mySetPenColor("Layer03Dark");
				break;
				case 2:
				mySetPenColor("Layer02Dark");
				break;
				case 3:
				mySetPenColor("Layer01Dark");
				break;
			}
		break;
	}
	
	if( gs_textbox_color.fillflag ) EndFilledRegion();


	switch(Get_Mode()){
		case 0: 
// printf("\nBlam!\n");
			mySetPenColor("White");
		break;
		case 1:
			mySetPenColor("Black");
		break;
	}
	SetPenSize(3);
	DrawLine(0, h);
	DrawLine(w, 0);
	DrawLine(0, -h);
	DrawLine(-w, 0);
	SetPenSize(1.5);

	// show text
	switch(Get_Mode()){
		case 0: 
			if(Dep>=2) mySetPenColor("White");
			else mySetPenColor("Black");
		break;
		case 1:
			if(Dep>=2) mySetPenColor("Black");
			else mySetPenColor("White");
		break;
	}
	// mySetPenColor(labelColor);
	MovePen(x+indent, textPosY);
	DrawTextString(textbuf);
	// add cursor if we have keyboard focus
	if ( gs_UIState.kbdItem == id && (clock() >> 8) & 1) 
	{
		//MovePen(x+indent+TextStringWidth(textbuf), textPosY);
		DrawTextString("_");
	}

	// If we have keyboard focus, we'll need to process the keys
	if ( gs_UIState.kbdItem == id )
	{
		switch (gs_UIState.keyPress)
		{
			case VK_RETURN:
			case VK_TAB:
				// lose keyboard focus.
				gs_UIState.kbdItem = 0;
				// If shift was also pressed, we want to move focus
				// to the previous widget instead.
				if ( gs_UIState.keyModifiers & KMOD_SHIFT )
					gs_UIState.kbdItem = gs_UIState.lastItem;
				// Also clear the key so that next widget won't process it
				gs_UIState.keyPress = 0;
				break;
			case VK_BACK:
				if( len > 0 ) {
					if (textbuf[len-1] < 0){
						--len; //汉字占2个字节且每个字节最高位都为1 by xdq @20210517
						OutputAscii(Index,'$',0);
					}
					textbuf[--len] = 0; //ASCII字符回退一个字节，汉字回退2个字节 by xdq @20210517 
					OutputAscii(Index,'$',0);
					textChanged = 1;
				}
				gs_UIState.keyPress = 0;
				break;
		}
		// char input：支持输入可见ASCII码字符[32,127]，和输入汉字（占2个字节且每个字节最高位都为1）by xdq @20210517
		if ((gs_UIState.charInput >= 32 && gs_UIState.charInput < 127 || gs_UIState.charInput < 0) && len+1 < buflen ) {
			textbuf[len] = gs_UIState.charInput;
			textbuf[++len] = 0;
			OutputAscii(Index,gs_UIState.charInput,1);
			gs_UIState.charInput = 0;
			textChanged = 1;
		}
	}

	gs_UIState.lastItem = id;

	if( gs_UIState.clickedItem==id && // must be clicked before
		! gs_UIState.mousedown )     // but now mouse button is up
	{
		gs_UIState.clickedItem = 0;
		gs_UIState.kbdItem = id;
	}

	return textChanged;
}


/* 画一个矩形 */
void MydrawRectangle(double x, double y, double w, double h, int fillflag,double gr)
{
	MovePen(x, y);
	if( fillflag ) StartFilledRegion(gr); 
	{
		DrawLine(0, h);
		DrawLine(w, 0);
		DrawLine(0, -h);
		DrawLine(-w, 0);
	}
	if( fillflag ) EndFilledRegion();
}

/* 画一个矩形，并在其内部居中显示一个字符串标签label */
void MydrawBox(double x, double y, double w, double h, int fillflag, char *label, char labelAlignment, char *labelColor)
{
	double fa = GetFontAscent();
	// rect
	MydrawRectangle(x,y,w,h,fillflag,1);
	// text
	if( label && strlen(label)>0 ) {
		mySetPenColor(labelColor);
		if( labelAlignment=='L' )
			MovePen(x+fa/2, y+h/2-fa/2);
		else if( labelAlignment=='R' )
			MovePen(x+w-fa/2-TextStringWidth(label), y+h/2-fa/2);
		else // if( labelAlignment=='C'
			MovePen(x+(w-TextStringWidth(label))/2, y+h/2-fa/2);
		DrawTextString(label);
	}
}

/* 显示字符串标签 */
void MydrawLabel(double x, double y, char *label)
{
	if( label && strlen(label)>0 ) {
		MovePen(x,y);
		DrawTextString(label);
	}
}


int GetESC(){
	return ESCC;
}