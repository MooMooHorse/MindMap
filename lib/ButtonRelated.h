#ifndef _ButtonRelated_h_

#define _ButtonRelated_h_


#include "imgui.h"
#include "graphics.h"
#include "extgraph.h"
#include "Line.h"
#include "TextBox.h"

void DrawButton();
int IfLineActivated();
void LineDeactivated();
void PushPendingPosition(double x,double y);

extern double winwidth, winheight;



#endif