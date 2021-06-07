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
extern double winwidth, winheight;   // ���ڳߴ�

// // ����������provided in libgraphics
// void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);

// �û�����ʾ����
// void display(void); 

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
	
	char* OUTPUTFILENAME1="../OUTPUTDATA/001.txt";
	char* OUTPUTFILENAME2="../OUTPUTDATA/002.txt";
	char* OUTPUTFILENAME3="../OUTPUTDATA/003.txt";

	freopen(OUTPUTFILENAME1,"w",stdout);
	
	printf("1111111111111111111111111111111!\n");//��һ�� ����
	

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

	MysetTextBoxColors("Blue","White","Red","White",1);

	AddTextBox(winwidth/2-1.5,winheight/2,winwidth/5,GetFontHeight()*2);
	
	return;

}



