#include "Line.h"
#include "imgui.h"
#include "mygui.h"
#include "graphics.h"
#include "extgraph.h"
#include "TextBox.h"
#include "ButtonRelated.h"
#include "Output.h"
#if defined(DEBUG)//defined in TextBox.h
#include <stdio.h>
#endif
typedef struct{
	double sx,sy,lx,ly;
}Line;

static Line PositionOfLine[101];// 最多 100 条线 编号从 1 开始
//要更多当然可以，但考虑实际情况...
static int NumberOfLines;

static Line ActivatedLine;
static int DrawActivatedLineOrNot;

void StoreLine(double sx,double sy,double lx,double ly){

	NumberOfLines++;

	PositionOfLine[NumberOfLines].sx=sx;
	PositionOfLine[NumberOfLines].sy=sy;
	PositionOfLine[NumberOfLines].lx=lx;
	PositionOfLine[NumberOfLines].ly=ly;
	OutputLine(sx,sy,lx,ly);
}

void DrawLines(){
	int i;
	for(i=1;i<=NumberOfLines;i++){
		Line li=PositionOfLine[i];
		MovePen(li.sx,li.sy);
		SetPenColor("Blue");
		SetPenSize(3);
		DrawLine(li.lx,li.ly);
	}
	if(DrawActivatedLineOrNot){
		Line li=ActivatedLine;
		MovePen(li.sx,li.sy);
		SetPenColor("Red");
		SetPenSize(3);
		DrawLine(li.lx,li.ly);
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
			StoreLine(x,y,ScaleXInches(xx)-x,winheight-ScaleXInches(yy)-y);
			PushPendingPosition(ScaleXInches(xx),winheight-ScaleXInches(yy));
		}
	}

}