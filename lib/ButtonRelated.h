#ifndef _ButtonRelated_h_

#define _ButtonRelated_h_

void DrawButton();
int IfLineActivated();
void LineDeactivated();
void PushPendingPosition(double x,double y,int Index);
void Clear();
int Get_Mode();
int Get_Style();
void ChangeStyleType(int s);

extern double winwidth, winheight;



#endif