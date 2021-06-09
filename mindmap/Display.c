#include "Display.h"
#include "Line.h"
#include "ButtonRelated.h"
#include "TextBox.h"
#include "graphics.h"
#include "mygui.h"
#include <string.h>

typedef enum{Dark,Light} MODEE;

static void mySetPenColor(char *color)
{
	if( color && strlen(color)>0 ) SetPenColor(color);
}

/*
* 功能： 显示背景
*/
static void DisplayBackGround(int Mode){
	double	w=GetWindowWidth();
	double  h=GetWindowHeight();


	switch (Mode){
		case Dark:
			mySetPenColor("Black");
			MydrawRectangle(0,0,w,h,1,1);
		break;
		case Light:
		
		break;
	}
}

/*
* 功能： 每当事件产生，都会刷新屏幕
*/
void display(){
	DisplayClear();

	DisplayBackGround(Get_Mode());

	DrawButton();

	DrawLines();

	DrawTextBox();

}