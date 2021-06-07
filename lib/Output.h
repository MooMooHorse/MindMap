#ifndef _Output_h_

#define _Output_h_

/*
功能： 打开各种对输出文档的写入操作
用法： 注释以后所有输出与输出文档的打开全部关闭
*/
#define OUTPUT 

void OutputSetting(int StyleName);
void OutputLine(double sx,double sy,double lx,double ly);
void OutputTextBox(double x,double y,double w,double h,int Index);
void OutputAscii(int Index,int ch,int doi);
void OutputFirstLine();
#endif