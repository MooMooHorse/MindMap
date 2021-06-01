#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"
#include "ButtonRelated.h"
#include "Line.h"
#include "TextBox.h"
extern double winwidth, winheight;   // 窗口尺寸

// 清屏函数，provided in libgraphics
void DisplayClear(void); 
// 计时器启动函数，provided in libgraphics
void startTimer(int id,int timeinterval);

// 用户的显示函数
void display(void); 

// 用户的字符事件响应函数

double winwidth, winheight;   // 窗口尺寸

void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI字符输入
	display(); //刷新显示
}

// 用户的键盘事件响应函数
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI获取键盘
	display(); // 刷新显示
}

// 用户的鼠标事件响应函数
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI获取鼠标
	DrawActivatedLine(x,y,button,event);
	TextBoxGetMouse(x,y,button,event);

	display(); // 刷新显示
}

void display()
{
	// 清屏
	DisplayClear();

	DrawButton();

	DrawLines();

	DrawTextBox();

}



void Main()
{
	SetWindowTitle("MindMap");
	InitGraphics();
#if defined(DEBUG)//defined in TextBox.h
	InitConsole();
#endif

	winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// 注册时间响应函数
	registerCharEvent(CharEventProcess);        // 字符
	registerKeyboardEvent(KeyboardEventProcess);// 键盘
	registerMouseEvent(MouseEventProcess);      // 鼠标

	setTextBoxColors("Blue",      "White",	"Red",	    "White",   1);

	AddTextBox(winwidth/2-1.5,winheight/2,winwidth/5,GetFontHeight()*2);
	
	return;

}



