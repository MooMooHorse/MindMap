#include "TextBox.h"

typedef struct{
	double x,y;
	double w,h;
}Textbox;


static Textbox PositionOfTextBox[100]; 

static int TextBoxIndex;

static int ActivatedTextBox;// 编号从 1 开始 = 0 表明未选中

bool INBOX(double x,double y,int k){

	return x >= PositionOfTextBox[k].x
		&& x <= (PositionOfTextBox[k].x+PositionOfTextBox[k].w)
		&& y >= PositionOfTextBox[k].y
		&& y <= (PositionOfTextBox[k].y+PositionOfTextBox[k].h)
	;

}

void TextBoxGetMouse(int x,int y,int button,int event){
	int i;
	for(i=1;i<=TextBoxIndex;i++){
		if(INBOX(ScaleXInches(x),ScaleXInches(y),i)) {
			ActivatedTextBox=i;
			break;
		}
	}
}


void AddTextBox(double x,double y,double w,double h){
	TextBoxIndex++;
	PositionOfTextBox[TextBoxIndex]=(Textbox){x,y,w,h};
}

int GetActivatedTextBox(){//接口 : 返回 ActivatedTextBox 的值
	return ActivatedTextBox;
}

void DrawTextBox(){
	int i;
	for(i=1;i<=TextBoxIndex;i++){
		textbox(GenUUID(i-1),
			PositionOfTextBox[i].x,
			PositionOfTextBox[i].y,
			PositionOfTextBox[i].w,
			PositionOfTextBox[i].h,
			"",0
		);
	}

}


