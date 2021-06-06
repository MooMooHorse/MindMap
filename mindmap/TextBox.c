#include "TextBox.h"



#if defined(DEBUG) //defined in TextBox.h
#include <stdio.h>
#endif


static Textbox PositionOfTextBox[100];

static int FatherOfTextBox[100];

static int TextBoxIndex;

static int ActivatedTextBox;// 编号从 1 开始 = 0 表明未选中

bool INBOX(double x,double y,int k){
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


void AddTextBox(double x,double y,double w,double h){
	TextBoxIndex++;
	PositionOfTextBox[TextBoxIndex].x=x;
	PositionOfTextBox[TextBoxIndex].y=y;
	PositionOfTextBox[TextBoxIndex].w=w;
	PositionOfTextBox[TextBoxIndex].h=h;
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
		
		textbox(GenUIID(i-1),
			PositionOfTextBox[i].x,
			PositionOfTextBox[i].y,
			PositionOfTextBox[i].w,
			PositionOfTextBox[i].h,
			BUFFER[i],sizeof(BUFFER[i])
		);
	}

}