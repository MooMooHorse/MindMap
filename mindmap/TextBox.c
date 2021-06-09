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

#include <string.h>
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

static int DepthOfTextBox[100];

static int TextBoxIndex;

static int ActivatedTextBox;// ��Ŵ� 1 ��ʼ = 0 ����δѡ��

//�ڲ����� �û��������
static int INBOX(double x,double y,int k){
	y=winheight-y;
	return x >= PositionOfTextBox[k].x
		&& x <= (PositionOfTextBox[k].x+PositionOfTextBox[k].w)
		&& y >= PositionOfTextBox[k].y
		&& y <= (PositionOfTextBox[k].y+PositionOfTextBox[k].h)
	;

}





/*
���ܣ��ı���callback����
�÷�����Ϊcallback��������
*/
void TextBoxGetMouse(int x,int y,int button,int event){
	int i;
	for(i=1;i<=TextBoxIndex;i++){
		if(INBOX(ScaleXInches(x),ScaleXInches(y),i)&&event==BUTTON_DOWN) {
			ActivatedTextBox=i;
			break;
		}
	}
}

/*
���ܣ� ����һ���ı���
�÷��� ����(x,y,w,h,fa) �ֱ�����ı���������꣬�ı����͸ߣ��ı����׵ı�ţ���1��ʼ��
ע����� ����ԭ��λ�ڴ������½ǣ������½����� (0,0)
*/

void AddTextBox(double x,double y,double w,double h,int fa){
	TextBoxIndex++;
	if(fa!=TextBoxIndex)
		FatherOfTextBox[TextBoxIndex]=fa;
	int dep=0;
	int cur=TextBoxIndex;
	while(FatherOfTextBox[cur]){
		cur=FatherOfTextBox[cur];
		dep++;
	}
	DepthOfTextBox[TextBoxIndex]=dep;
	PositionOfTextBox[TextBoxIndex].x=x;
	PositionOfTextBox[TextBoxIndex].y=y;
	PositionOfTextBox[TextBoxIndex].w=w;
	PositionOfTextBox[TextBoxIndex].h=h;
	OutputTextBox(x,y,w,h,TextBoxIndex,fa);
}
//�ӿ� : ���� ActivatedTextBox ��ֵ
Textbox* GetActivatedTextBox(){
	if(!ActivatedTextBox) return NULL;
	return &PositionOfTextBox[ActivatedTextBox];
}
//�ӿ� : ���� ActivatedTextBox Index ��ֵ
int GetActivatedTextBoxIndex(){
	return ActivatedTextBox;
}

static char BUFFER[25][80]={
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter",
		"Please Enter","Please Enter","Please Enter","Please Enter","Please Enter"
};

/*
���ܣ� ����ı���
�÷��� ��ButtonRelated.c �µ���Clear() �����е��ü���
*/
void ClearTextBox(){
	char CP[20]="Please Enter";
	for(int i=0;i<25;i++)
		for(int j=0;j<12;j++)
			BUFFER[i][j]=CP[j];
	TextBoxIndex=0;
	ActivatedTextBox=0;
	memset(FatherOfTextBox,0,sizeof(FatherOfTextBox));
	memset(DepthOfTextBox,0,sizeof(DepthOfTextBox));
}

/*
���ܣ�ûˢ��һ�λ��������ı���
�÷���display�����ڵ���
*/
void DrawTextBox(){
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
			BUFFER[i],sizeof(BUFFER[i]),i,DepthOfTextBox[i]
		);
#if defined(DEBUG)
	//	printf("%d %d\n",i,DepthOfTextBox[i]);
#endif
	}
}

typedef enum{Del=0,Ins} DOII;
void EditBuffer(int Index,int ch,int doi){
	int Len=strlen(BUFFER[Index]);
	switch(doi){

		case Del:
			if(Len>0){
				Len--;
				BUFFER[Index][Len]=0;
			}
		break;
		case Ins:
			BUFFER[Index][Len]=ch;
			Len++;
		break;
		
	}
}