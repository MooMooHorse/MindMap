#ifndef _Line_h_

#define _Line_h_



#include "imgui.h"
#include "graphics.h"
#include "extgraph.h"
#include "TextBox.h"
#include "ButtonRelated.h"
extern double winwidth, winheight;

void StoreLine(double sx,double sy,double lx,double ly);
void DrawLines();
void DrawActivatedLine(int x,int y,int button,int event);

#endif