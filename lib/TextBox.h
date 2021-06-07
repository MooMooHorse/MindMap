#ifndef _TextBox_h_

#define _TextBox_h_
//#define DEBUG


typedef struct{
	double x,y;
	double w,h;
} Textbox;
bool INBOX(double x,double y,int k);
void TextBoxGetMouse(int x,int y,int button,int event);
void AddTextBox(double x,double y,double w,double h);
Textbox* GetActivatedTextBox();
void DrawTextBox();
void TextBoxGetKey(int key,int event);
extern double winwidth, winheight;
#endif