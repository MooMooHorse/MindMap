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


static Point StackForTextBox[100]; // 可以加文本框的位置
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
功能： 清空所有影响显示的变量。
*/
void Clear(){
	ClearLine();
	ClearTextBox();
	ClearButton();
	OutputClear();
}
/*
功能：画出所有按钮。
*/
void DrawButton(){
	double fH = GetFontHeight();
	double h = fH*2;  // 控件高度
	double w = winwidth/5; // 控件宽度
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
		
		AddTextBox(StackForTextBox[StackTop].x-w/2,StackForTextBox[StackTop].y-h/2,w,h,StackForTextBox[StackTop].Ind);//w,h 暂定和 button 一样 可以调整 可以优化成可用户调节大小
		StackTop--;
	}

	

}

/*
* 功能：存储剩余位置
* 注意事项： 剩余位置指在添加线后没有连接文本框的线末端位置。
*/
void PushPendingPosition(double x,double y,int Index){
	StackTop++;
	StackForTextBox[StackTop].x=x;
	StackForTextBox[StackTop].y=y;
	StackForTextBox[StackTop].Ind=Index;
}


/*
* 功能：API 传出激活线段编号
*/
int IfLineActivated(){
	return LineActivated;
}
/*
* 功能：API 去激活线段
*/
void LineDeactivated(){
	LineActivated=0;
}
/*
* 功能：API 改变样式
*/
void ChangeStyleType(int s){
	StyleType=s;
}