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


extern double winwidth, winheight;   // ���ڳߴ�

// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);


// �û����ַ��¼���Ӧ����

double winwidth, winheight;   // ���ڳߴ�

void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	MyuiGetChar(ch);
	display(); //ˢ����ʾ
}

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI��ȡ����
	MyuiGetKeyboard(key,event); // GUI��ȡ����
	TextBoxGetKey(key,event);
	display(); // ˢ����ʾ
}

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI��ȡ���
	MyuiGetMouse(x,y,button,event); //GUI��ȡ���
	DrawActivatedLine(x,y,button,event);
	TextBoxGetMouse(x,y,button,event);

	display(); // ˢ����ʾ
}

void Main(){
// #if defined(DEBUG)
	freopen("../METADATA/debug.txt","w",stdout);
// #endif

	ReadModel(1);
	
#if defined(OUTPUT)
	char* OUTPUTFILENAME1="../OUTPUTDATA/usro1.txt";
	char* OUTPUTFILENAME2="../OUTPUTDATA/usro2.txt";
	char* OUTPUTFILENAME3="../OUTPUTDATA/usro3.txt";

	freopen(OUTPUTFILENAME1,"w",stdout);
#endif

	OutputFirstLine();

	OutputSetting(1);
	

	/*
	* ����ļ�ǰ׺: 0000 1111 (�ո�ֻ��Ϊ�˸���ֱ�ۣ����ʱ��Ӧ������ո�)
	* ����ļ�ֻӦ���� 0 1 ���з� �����ļ���ͷһ�����ϵļ�ͷ
	* ���� �ļ���ͷ���ϼ�ͷ���� δ֪���� �����ڶ���������ļ�����Ӱ�� ����׼����������Դ
	*/
	
	SetWindowTitle("MindMap");
	
	InitGraphics();
	winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// ע��ʱ����Ӧ����
	registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���

	MysetTextBoxColors("Black","White","Red","White",1);

	AddTextBox(winwidth/2-1.5,winheight/2,winwidth/5,GetFontHeight()*2);
	
	return;

}



