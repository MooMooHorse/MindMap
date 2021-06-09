#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"
#include "ButtonRelated.h"
#include "Line.h"
#include "TextBox.h"
#include "Display.h"
#include "Output.h"
#include "mygui.h"
#include "MyInput.h"


extern double winwidth, winheight;   // 窗口尺寸

// 清屏函数，provided in libgraphics
void DisplayClear(void); 
// 计时器启动函数，provided in libgraphics
void startTimer(int id,int timeinterval);


// 用户的字符事件响应函数

double winwidth, winheight;   // 窗口尺寸

void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI字符输入
	MyuiGetChar(ch);
	display(); //刷新显示
}

// 用户的键盘事件响应函数
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI获取键盘
	MyuiGetKeyboard(key,event); // GUI获取键盘
	display(); // 刷新显示
}

// 用户的鼠标事件响应函数
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI获取鼠标
	MyuiGetMouse(x,y,button,event); //GUI获取鼠标
	DrawActivatedLine(x,y,button,event);
	TextBoxGetMouse(x,y,button,event);

	display(); // 刷新显示
}

void Main(){
#if defined(DEBUG)
	freopen("../METADATA/debug.txt","w",stdout);
#endif

	// ReadModel(1);
	
#if defined(OUTPUT)
	char* OUTPUTFILENAME="../OUTPUTDATA/usro.txt";

	freopen(OUTPUTFILENAME,"w",stdout);
#endif
	

	OutputFirstLine();

	OutputSetting(1);
	

	/*
	* 输出文件前缀: 0000 1111 (空格只是为了更加直观，输出时不应该输出空格)
	* 输出文件只应包含 0 1 换行符 还有文件开头一个向上的箭头
	* 其中 文件开头向上箭头属于 未知因素 但由于对输出输入文件毫无影响 并不准备考虑其来源
	*/
	
	SetWindowTitle("MindMap");
	
	InitGraphics();

	DefineColor("Layer01Dark",0.65,0.65,0.65);
	DefineColor("Layer02Dark",0.5,0.5,0.5);
	DefineColor("Layer03Dark",0.25,0.25,0.25);
	DefineColor("Layer04Dark",0,0,0);
	
	winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// 注册时间响应函数
	registerCharEvent(CharEventProcess);        // 字符
	registerKeyboardEvent(KeyboardEventProcess);// 键盘
	registerMouseEvent(MouseEventProcess);      // 鼠标

	MysetTextBoxColors("Black","White","Red","White",1);

//	AddTextBox(winwidth/2-1.5,winheight/2,winwidth/5,GetFontHeight()*2,1);
	
	return;

}



