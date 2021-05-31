#ifndef _TextBox_h_

#define _TextBox_h_

bool INBOX(double x,double y,int k);
void TextBoxGetMouse(int x,int y,int button,int event);
void AddTextBox(double x,double y,double w,double h);
int GetActivatedTextBox();
void DrawTextBox();
#endif