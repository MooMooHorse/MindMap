#include "Line.h"
#include "imgui.h"
#include "mygui.h"
#include "graphics.h"
#include "extgraph.h"
#include "TextBox.h"
#include "ButtonRelated.h"
#include "Output.h"

#include <string.h>
#include <math.h>
#if defined(DEBUG)//defined in TextBox.h
#include <stdio.h>
#endif
typedef struct{
	double sx,sy,lx,ly;
	int fa;
}Line;

static Line PositionOfLine[101];
static int NumberOfLines;

static Line ActivatedLine;
static int DrawActivatedLineOrNot;

/*
功能： 清空线
用法： 在ButtonRelated.c 下的总Clear() 函数中调用即可
*/
void ClearLine(){
	NumberOfLines=0;
	LineDeactivated();
	DrawActivatedLineOrNot=0;
}

/*
功能： 存储线
用法： 传入线起点(sx,sy) 线长度向量(lx,ly) 线连接文本框编号
*/
void StoreLine(double sx,double sy,double lx,double ly,int Index){

	NumberOfLines++;

	PositionOfLine[NumberOfLines].sx=sx;
	PositionOfLine[NumberOfLines].sy=sy;
	PositionOfLine[NumberOfLines].lx=lx;
	PositionOfLine[NumberOfLines].ly=ly;
	PositionOfLine[NumberOfLines].fa=Index;
	OutputLine(sx,sy,lx,ly,Index);//+fa
}
static void DrawCurve(double sx,double sy,double lx,double ly){
	int SPLIT=200;
	double t=ly/SPLIT;
	double lasx=0,lasy=0;
	for(int i=1;i<=SPLIT;i++){
		double cury=t*i;
		double curx=lx*cury*cury/ly/ly;
		MovePen(sx+curx,sy+cury);
		DrawLine(curx-lasx,cury-lasy);
		lasx=curx,lasy=cury;
	}
}
void DrawLines(){
	int i;
	for(i=1;i<=NumberOfLines;i++){
		Line li=PositionOfLine[i];
		MovePen(li.sx,li.sy);
		switch(Get_Mode()){
			case 0: 
				SetPenColor("White");
			break;
			case 1:
				SetPenColor("Black");
			break;
		}
		SetPenSize(3);
		switch(Get_Style()){
			case 1: 
				DrawLine(li.lx,li.ly);
			break;
			case 2:
				DrawCurve(li.sx,li.sy,li.lx,li.ly);
			break;
			case 3:
				DrawCurve(li.sx,li.sy,li.lx,li.ly);
			break;
		}
	}
	if(DrawActivatedLineOrNot){
		Line li=ActivatedLine;
		MovePen(li.sx,li.sy);
		SetPenColor("Gray");
		SetPenSize(3);
		switch(Get_Style()){
			case 1: 
				DrawLine(li.lx,li.ly);
			break;
			case 2:
				// DrawLine(li.lx,li.ly);
				DrawCurve(li.sx,li.sy,li.lx,li.ly);
			break;
			case 3:
				DrawCurve(li.sx,li.sy,li.lx,li.ly);
			break;
		}
	}
}

void DrawActivatedLine(int xx,int yy,int button,int event){

	if(IfLineActivated()){
		
		Textbox *p=GetActivatedTextBox();
		double x=p->x+p->w/2;
		double y=p->y+p->h/2;
		MovePen(x,y);
		//printf("activated!\n");
		if(event!=BUTTON_DOWN){
			DrawActivatedLineOrNot=1;//draw
		}
		else DrawActivatedLineOrNot=0;
		ActivatedLine.sx=x;
		ActivatedLine.sy=y;
		ActivatedLine.lx=ScaleXInches(xx)-x;
		ActivatedLine.ly=winheight-ScaleXInches(yy)-y;
		if(event==BUTTON_DOWN){
			LineDeactivated();
			StoreLine(x,y,ScaleXInches(xx)-x,winheight-ScaleXInches(yy)-y,GetActivatedTextBoxIndex());
			PushPendingPosition(ScaleXInches(xx),winheight-ScaleXInches(yy),GetActivatedTextBoxIndex());
		}
	}

}