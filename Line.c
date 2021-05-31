#include "line.h"


static Line PositionOfLine[101];// 最多 100 条线 编号从 1 开始
//要更多当然可以，但考虑实际情况...
static int NumberOfLines;

void StoreLine(double sx,double sy,double lx,double ly){

	NumberOfLines++;

	PositionOfLine[NumberOfLines]=(Line){sx,sy,lx,ly};

}

void DrawLine(){
	int i;
	for(i=1;i<=NumberOfLines;i++){
		Line li=PositionOfLine[i];
		MovePen(li.sx,li.sy);
		SetPenColor("Blue");
		SetPenSize(3);
		DrawLine(lx,ly);
	}
}