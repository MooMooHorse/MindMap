#ifndef _Output_h_

#define _Output_h_

/*
功能： 打开各种对输出文档的写入操作（DEBUG文档除外）
用法： 注释以后所有输出与输出文档的打开全部关闭
*/
#define OUTPUT 

void OutputSetting(int StyleName);
void OutputLine(double sx,double sy,double lx,double ly,int Index);
void OutputTextBox(double x,double y,double w,double h,int Index,int fa);
void OutputAscii(int Index,int ch,int doi);
void OutputFirstLine();
void OutputClear();
void OutputStyleType(int StyleType);
void OutputTextBoxProperty(int Index,int aod);
#endif