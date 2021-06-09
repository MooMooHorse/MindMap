#ifndef _Line_h_

#define _Line_h_




extern double winwidth, winheight;

void ClearLine();
void StoreLine(double sx,double sy,double lx,double ly,int Index);
void DrawLines();
void DrawActivatedLine(int x,int y,int button,int event);

#endif