#ifndef _TextBox_h_

#define _TextBox_h_
// #define DEBUG


typedef struct{
	double x,y;
	double w,h;
} Textbox;
void TextBoxGetMouse(int x,int y,int button,int event);
void AddTextBox(double x,double y,double w,double h,int fa);
Textbox* GetActivatedTextBox();
int GetActivatedTextBoxIndex();
void DrawTextBox();
void EditBuffer(int Index,int ch,int doi);
void ClearTextBox();
void ChangeTextBoxProperty(int Index,int doa);
void ChangeGap(double gp);
double GetGap();
extern double winwidth, winheight;
#endif