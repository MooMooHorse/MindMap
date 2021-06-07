#include "MyInput.h"
#include <stdio.h>
typedef enum{STYLE01=0,STYLE02,STYLE03} ALLSTYLES;
typedef enum{INSTR1=0,INSTR2,INSTR3,INSTR4} InstructionNames;
/*
* 功能： 如果 当前字符串前几位符合合法前缀(0000/1111)
* 返回对应的合法特征
* 合法特征： '0000'/'1111'
*/
static int CheckLegal(char X[]){
    if(X[0]==X[1] && X[1]==X[2] && X[2]==X[3] && (X[0]=='0'||X[0]=='1')){
        if(X[0]=='0') return 1;
        else return 2;
    }
    return 0;
}

/*
* 功能：能够导入三种不同样式的文件模板。
* 用法: 主函数入口，在各种初始化之前，尤其是在打开输出标准流之前调用
* “输出标准流”： stdout
* 传入 Stylename 属于有限数集 {0,1,2}
* 注意事项：
*
* 其中 文件路径为模板文件路径，如果改变文件结构，请改变路径
*
* 各种读入文件中 每一行中间不能有空格
*
*/
void ReadModel(int StyleName){
    char* FILENAME;
    switch (StyleName){
        case(STYLE01): FILENAME="../OUTPUTDATA/001.txt"; 
        case(STYLE02): FILENAME="../OUTPUTDATA/002.txt"; 
        case(STYLE03): FILENAME="../OUTPUTDATA/003.txt";
    }
    freopen(FILENAME,"r",stdin);
    char ST[128];
    int LineNumber=0,j;
    while(scanf("%s",ST!=EOF)){
        if(!LineNumber) continue;//忽略第一行
        if(CheckLegal(ST)){
            int Instr=((ST[4]-'0')<<1)+ST[5]-'0';
            switch(Instr){
                case (INSTR1):

                break;
                case (INSTR2):

                break;
                case (INSTR3):

                break;
                case(INSTR4):

                break;

            }
        }   

        LineNumber++;
    }

    fclose(stdin);//关闭标准输入流，请注意不要注释掉
}
