#ifndef _Line_h_

#define _Line_h_

typedef struct{
	double sx,sy,lx,ly;
}Line;

#include "imgui.h"
#include "graphics.h"
#include "extgraph.h"


void StoreLine(double sx,double sy,double lx,double ly);

void DrawLine();
#endif