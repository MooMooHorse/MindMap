#include "ButtonRelated.h"
#include "imgui.h"
#include "mygui.h"
#include "graphics.h"
#include "extgraph.h"
#include "Line.h"
#include "TextBox.h"

typedef struct{
	double x,y;
}Point;


static Point StackForTextBox[100]; // ���Լ��ı����λ��
static int StackTop;

static int LineActivated;




void DrawButton(){
	double fH = GetFontHeight();
	double h = fH*2;  // �ؼ��߶�
	double w = winwidth/5; // �ؼ����
	SetPenSize(1.5);
	if( button(GenUIID(0), winwidth-w-0.01, h*2, w, h, "Add Line") )
	{	
		if(GetActivatedTextBox()==NULL){
			drawLabel(5,5,"Please choose a valid starting textbox first");
			return ;
		}
		LineActivated=1;


	}

	SetPenSize(1.5);
	if( button(GenUIID(0), winwidth-w-0.01, 0.01, w, h, "Add TextBox") )
	{	
		if(StackTop==0){
			drawLabel(5,5,"Please draw a line first");
			return ;
		}
		AddTextBox(StackForTextBox[StackTop].x-w/2,StackForTextBox[StackTop].y-h/2,w,h);//w,h �ݶ��� button һ�� ���Ե��� �����Ż��ɿ��û����ڴ�С
		StackTop--;
	}

}

void PushPendingPosition(double x,double y){
	StackTop++;
	StackForTextBox[StackTop].x=x;
	StackForTextBox[StackTop].y=y;
}

int IfLineActivated(){
	return LineActivated;
}
void LineDeactivated(){
	LineActivated=0;
}