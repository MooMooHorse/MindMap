#include "MyInput.h"
#include <stdio.h>
#include <string.h>
#include "Line.h"
#include "graphics.h"
#include "TextBox.h"
#include "ButtonRelated.h"
typedef enum{STYLE01=1,STYLE02,STYLE03} ALLSTYLES;
typedef enum{INSTR1=0,INSTR2,INSTR3,INSTR4} InstructionNames;
typedef enum{FONT_COLOR=0,LINE_COLOR,TEXTBOXFRAME_COLOR,TEXTBOXFILL_COLOR} PROPERTY1;
static char* Font_Color;
static char* Line_Color;
static char* TextBoxFrame_Color;
static char* TextBoxFill_Color;
char* MAPP[16]={
    "Black", 
    "Dark Gray",
    "Gray",
    "Light Gray",
    "White",
    "Brown",
    "Red",
    "Orange",
    "Yellow",
    "Green",
    "Blue",
    "Violet",
    "Magenta",
    "Cyan"
};




typedef enum{IntegerPart=0,DoublePart} IOD; 
static double GetDoubleNumber(int st,char Str[]){
    double Sign=1.0;
    if(Str[st]=='-'){
        Sign=-Sign;
        st++;
    }
    double ret=0;
    double Temp=0.1;
    int InOrDo=0;
    while(Str[st]!='_'){
        if(Str[st]=='.'){
            InOrDo^=1;
            st++;
            continue;
        }
        switch(InOrDo){
            case IntegerPart:
                ret=ret*10+Str[st]-'0';
            break; 
            case DoublePart:
                ret=ret+Temp*(Str[st]-'0');
                Temp/=10.0;
            break;
        }
        st++;
    }
    return ret*Sign;
}




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
* 功能： 四个接口，可以读入当前的属性值
*/
char* SettingAPI01_GetFontColor(){
    return Font_Color;
}
char* SettingAPI02_GetLineColor(){
    return Line_Color;
}
char* SettingAPI03_GetTextBoxFrameColor(){
    return TextBoxFrame_Color;
}
char* SettingAPI04_GetTextBoxFillColor(){
    return TextBoxFill_Color;
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
    // char* FILENAME;
    // switch (StyleName){
    //     case STYLE01: FILENAME="../OUTPUTDATA/001.txt"; break;
    //     case STYLE02: FILENAME="../OUTPUTDATA/002.txt"; break;
    //     case STYLE03: FILENAME="../OUTPUTDATA/003.txt"; break;
    // }
    // freopen(FILENAME,"r",stdin);
    // printf("%s\n",FILENAME);
    char ST[128];
    int LineNumber=0,j,Property,Val;
    int STY;
    
    while(scanf("%s",ST)!=EOF){
        // printf("%d\n",LineNumber);
            // printf("Legal!\n");
        if(!LineNumber){
            LineNumber++;
            continue;//忽略第一行
        }
        // printf("%d\n",LineNumber);
        if(CheckLegal(ST)){
            Property=((ST[8]-'0')<<3)+((ST[9]-'0')<<2)+((ST[10]-'0')<<1)+ST[11]-'0';
            Val=((ST[12]-'0')<<3)+((ST[13]-'0')<<2)+((ST[14]-'0')<<1)+ST[15]-'0';
            int Instr=((ST[4]-'0')<<1)+ST[5]-'0';
            if(ST[strlen(ST)-1]=='0'){
                // printf("%d\n",Instr);
                switch(Instr){
                    case INSTR1:
                        switch(StyleName){
                            case STYLE01:
                                switch (Property){
                                    case FONT_COLOR:  
                                        Font_Color=MAPP[Val];
                                    break;
                                    case LINE_COLOR: 
                                        Line_Color=MAPP[Val];
                                    break;
                                    case TEXTBOXFRAME_COLOR: 
                                        TextBoxFrame_Color=MAPP[Val];
                                    break;
                                    case TEXTBOXFILL_COLOR: 
                                        TextBoxFill_Color=MAPP[Val];
                                    break;
                                }
                            break;
                            case STYLE02:

                            break;
                            case STYLE03:

                            break;
                        }
                    break;
                    case INSTR2:
                        j=7;
                        double sx,sy,lx,ly;
                        int Ind;
                        sx=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        sy=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        lx=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        ly=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        Ind=GetDoubleNumber(j,ST);
                        StoreLine(sx,sy,lx,ly,Ind);
                    break;
                    case INSTR3:
                        j=7;
                        double x,y,w,h;
                        int id,fa;
                        x=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        y=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        w=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        h=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        id=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        fa=GetDoubleNumber(j,ST);
                        AddTextBox(x,y,w,h,fa);
                    break;
                    case INSTR4:
                        j=7;
                        int Index,doi;
                        int ch;
                        #if defined(DEBUG)
                        // printf("%s\n",ST);
                        #endif
                        Index=GetDoubleNumber(j,ST);
                        while(ST[j]!='_') j++;
                        j++;
                        ch=GetDoubleNumber(j,ST);
                        // printf("%d\n",ch);
                        while(ST[j]!='_') j++;
                        j++;
                        doi=ST[j]-'0';
                        // printf("%d %c %d\n",Index,ch,doi);
                        EditBuffer(Index,ch,doi);
                    break;

                }
            }
            else{
                switch(Instr){
                    case INSTR1:
                        Clear();
                    break;
                    case INSTR2:
                        
                        j=7;
                        STY=GetDoubleNumber(j,ST);
                        ChangeStyleType(STY);
                    break;
                }
            }
        }   

        LineNumber++;
    }

    fclose(stdin);//关闭标准输入流，请注意不要注释掉
}

