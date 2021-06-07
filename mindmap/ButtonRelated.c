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
	if( Mybutton(GenUIID(0), 0.01, 0.01, w/5, h, "1") ){

	}
	if( Mybutton(GenUIID(0), 0.01+w/5, 0.01, w/5, h, "2") ){
		
	}
	if( Mybutton(GenUIID(0), 0.01+w/5*2, 0.01, w/5, h, "3") ){
		
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