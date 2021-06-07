#include "TextBox.h"

#include "imgui.h"
#include "mygui.h"

#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "Output.h"

#if defined(DEBUG) //defined in TextBox.h
#include <stdio.h>
#endif

#if !defined(KMOD_SHIFT)
#define KMOD_SHIFT 0x01
#define KMOD_CTRL  0x02
#endif


static Textbox PositionOfTextBox[100];

static int FatherOfTextBox[100];

static int TextBoxIndex;

static int ActivatedTextBox;// 编号从 1 开始 = 0 表明未选中

int INBOX(double x,double y,int k){
	y=winheight-y;
	return x >= PositionOfTextBox[k].x
		&& x <= (PositionOfTextBox[k].x+PositionOfTextBox[k].w)
		&& y >= PositionOfTextBox[k].y
		&& y <= (PositionOfTextBox[k].y+PositionOfTextBox[k].h)
	;

}

void TextBoxGetMouse(int x,int y,int button,int event){
	int i;
	for(i=1;i<=TextBoxIndex;i++){
		if(INBOX(ScaleXInches(x),ScaleXInches(y),i)&&event==BUTTON_DOWN) {
			ActivatedTextBox=i;
			break;
		}
	}
}

static int keyModifiers;
static int keyPress;
void TextBoxGetKey(int key,int event){
	if( event==KEY_DOWN ) 
	{
		switch (key ) 
		{
			case VK_SHIFT:
				keyModifiers |= KMOD_SHIFT;
				break;
			case VK_CONTROL:
				keyModifiers |= KMOD_CTRL;
				break;
			default:
				keyPress = key;
		}
	} 
	else if( event==KEY_UP )
	{
		switch (key ) 
		{
			case VK_SHIFT:
				keyModifiers &= ~KMOD_SHIFT;
				break;
			case VK_CONTROL:
				keyModifiers &= ~KMOD_CTRL;
				break;
			default:
				keyPress = 0;
		}
	}
}


void AddTextBox(double x,double y,double w,double h){
	TextBoxIndex++;
	PositionOfTextBox[TextBoxIndex].x=x;
	PositionOfTextBox[TextBoxIndex].y=y;
	PositionOfTextBox[TextBoxIndex].w=w;
	PositionOfTextBox[TextBoxIndex].h=h;
	OutputTextBox(x,y,w,h,TextBoxIndex);
}

Textbox* GetActivatedTextBox(){//接口 : 返回 ActivatedTextBox 的值
	if(!ActivatedTextBox) return NULL;
	return &PositionOfTextBox[ActivatedTextBox];
}

void DrawTextBox(){
	static char BUFFER[25][80]={
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter"
	};
	int i;
#if defined(DEBUG)
//	printf("%d\n",TextBoxIndex);
#endif
	SetPenSize(1.5);
	for(i=1;i<=TextBoxIndex;i++){
		
		Mytextbox(GenUIID(i-1),
			PositionOfTextBox[i].x,
			PositionOfTextBox[i].y,
			PositionOfTextBox[i].w,
			PositionOfTextBox[i].h,
			BUFFER[i],sizeof(BUFFER[i]),i
		);
	}

}