#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"
#include "ButtonRelated.h"
#include "Line.h"
#include "TextBox.h"
extern double winwidth, winheight;   // ���ڳߴ�

// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);

// �û�����ʾ����
void display(void); 

// �û����ַ��¼���Ӧ����

double winwidth, winheight;   // ���ڳߴ�

void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	display(); //ˢ����ʾ
}

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI��ȡ����
	display(); // ˢ����ʾ
}

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI��ȡ���
	DrawActivatedLine(x,y,button,event);
	TextBoxGetMouse(x,y,button,event);

	display(); // ˢ����ʾ
}

void display()
{
	// ����
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

	// ע��ʱ����Ӧ����
	registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���

	setTextBoxColors("Blue",      "White",	"Red",	    "White",   1);

	AddTextBox(winwidth/2-1.5,winheight/2,winwidth/5,GetFontHeight()*2);
	
	return;

}



