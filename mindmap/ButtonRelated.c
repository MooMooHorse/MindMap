#include "ButtonRelated.h"
#include "imgui.h"
#include "mygui.h"
#include "graphics.h"
#include "extgraph.h"
#include "Line.h"
#include "TextBox.h"
#include "Output.h"
#include "MyInput.h"
#include <string.h>

typedef struct{
	double x,y;
	int Ind;
}Point;


static Point StackForTextBox[100]; // ���Լ��ı����λ��
static int StackTop;

static int LineActivated;

static int StyleType=1;
static Mode=0;
static void ClearButton(){
	StackTop=0;
	LineActivated=0;
	memset(StackForTextBox,0,sizeof(StackForTextBox));
}

int Get_Mode(){
	return Mode;//dark mode
}
int Get_Style(){
	return StyleType;
}


/*
���ܣ� �������Ӱ����ʾ�ı�����
*/
void Clear(){
	ClearLine();
	ClearTextBox();
	ClearButton();
	OutputClear();
}
/*
���ܣ��������а�ť��
*/
void DrawButton(){
	double fH = GetFontHeight();
	double h = fH*2;  // �ؼ��߶�
	double w = winwidth/5; // �ؼ����
	SetPenSize(1.5);
	if( Mybutton(GenUIID(0), 0.01, 0.01, w/5, h, "1") ){
		StyleType=1;
		Clear();
		freopen("../OUTPUTDATA/001.txt","r",stdin);
		ReadModel(1);
		fclose(stdin);
		OutputStyleType(StyleType);
	}
	if( Mybutton(GenUIID(0), 0.01+w/5, 0.01, w/5, h, "2") ){
		StyleType=2;	
		Clear();
		freopen("../OUTPUTDATA/002.txt","r",stdin);
		ReadModel(2);
		fclose(stdin);
		OutputStyleType(StyleType);
	}
	if( Mybutton(GenUIID(0), 0.01+w/5*2, 0.01, w/5, h, "3") ){
		StyleType=3;
		Clear();
		freopen("../OUTPUTDATA/003.txt","r",stdin);
		ReadModel(3);
		fclose(stdin);
		OutputStyleType(StyleType);
	}
	if( Mybutton(GenUIID(0), 0.01+w/5*3, 0.01, w, h, "Clear") ){
		Clear();
	}
	if( Mybutton(GenUIID(0), 0, winheight-h, w, h, "Import") ){
		Clear();
		freopen("../INPUTDATA/usri.txt","r",stdin);
		ReadModel(1);
		fclose(stdin);
	}
	if( Mybutton(GenUIID(0), 0.01+w/5*3+w, 0.01, w, h, "Add Init Button") ){
		switch (StyleType){
			case 1:
				AddTextBox(winwidth/2-1.5,winheight/2,winwidth/5,GetFontHeight()*2,1);
			break;
			case 2:
				AddTextBox(0,winheight/2,winwidth/5,GetFontHeight()*2,1);
			break;
			case 3:
				AddTextBox(0,winheight/2,winwidth/5,GetFontHeight()*2,1);
				AddTextBox(winwidth-w,winheight/2,winwidth/5,GetFontHeight()*2,2);
		}

	}
	if( Mybutton(GenUIID(0), 0.01+w/5*3+2*w, 0.01, w, h, "Dark/Light") ){
		Mode^=1;
	}
	SetPenSize(1.5);
	if( Mybutton(GenUIID(0), winwidth-w-0.01, h*2, w, h, "Add Line") )
	{	
		if(GetActivatedTextBox()==NULL){
			MydrawLabel(5,5,"Please choose a valid starting textbox first");
			return ;
		}
		LineActivated=1;


	}

	SetPenSize(1.5);
	if( Mybutton(GenUIID(0), winwidth-w-0.01, 0.01, w, h, "Add TextBox") )
	{	
		if(StackTop==0){
			MydrawLabel(5,5,"Please draw a line first");
			return ;
		}
		
		AddTextBox(StackForTextBox[StackTop].x-w/2,StackForTextBox[StackTop].y-h/2,w,h,StackForTextBox[StackTop].Ind);//w,h �ݶ��� button һ�� ���Ե��� �����Ż��ɿ��û����ڴ�С
		StackTop--;
	}

	

}

/*
* ���ܣ��洢ʣ��λ��
* ע����� ʣ��λ��ָ������ߺ�û�������ı������ĩ��λ�á�
*/
void PushPendingPosition(double x,double y,int Index){
	StackTop++;
	StackForTextBox[StackTop].x=x;
	StackForTextBox[StackTop].y=y;
	StackForTextBox[StackTop].Ind=Index;
}


/*
* ���ܣ�API ���������߶α��
*/
int IfLineActivated(){
	return LineActivated;
}
/*
* ���ܣ�API ȥ�����߶�
*/
void LineDeactivated(){
	LineActivated=0;
}
/*
* ���ܣ�API �ı���ʽ
*/
void ChangeStyleType(int s){
	StyleType=s;
}