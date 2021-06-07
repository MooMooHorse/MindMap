#include "Output.h"
#include <string.h>
#include <stdio.h>



/*
* 目前指令 为 16 位二进制
* 关于 "指令" 的特殊说明
*/

/*
* 指令前缀： 为了防止不合法的输出干扰 特别加上的鉴别合法指令标志 二进制下(1111/0000) 
* 前缀为 1111 的表明已经是 2进制
* 否则一律直接编码处理
*/
static void PrintPrefix1(){
    printf("1111");
}
static void PrintPrefix0(){
	printf("0000");
}

/*
* 功能：打印二进制指令中的某些值,并以字符串的形式返回
*/
char* DecimalToBinaryString(int x){
	static char RetStr[4]={'0','0','0','0'};
	int i=0;
	while(x){
		RetStr[3-i]+=(x&1);
		x>>=1;
		i++;
	}
	char *ptr=&RetStr[0];
	return ptr;
}

/*
* 功能： 把当前的setting转化成指令 
*
* 指令格式：
*
* (1111)       00      Instruction[9:8]      Instruction[7:4]   Instruction[3:0]
* 指令前缀    指令名          样式种类                属性名              属性值
*
*
* 指令名：    当前指令是样式设定指令，指令名为00
* 样式种类：  当前处于第种样式，不同样式 属性名集合可能不同
* 属性名：    当前声明的属性名
* 属性值：    当前声明的属性值
* 
* 用法：      本身每个样式，都有默认的Setting，建议用户不更改模板样式中的Setting，而是通过在用户输入二进制文件
* 中输入合法的指令，覆盖Setting
* Setting 的合法属性名与对应属性值如下
* 属性名二进制     属性名含义         属性值二进制         属性值对应含义
*    0000          字的颜色           0000                "Black"
*    0000          字的颜色           0001                "Dark Gray"
*    0000          字的颜色           0010                "Gray"
*    0000          字的颜色           0011                "Light Gray"
*    0000          字的颜色           0100                "White"
*    0000          字的颜色           0101                "Brown"
*    0000          字的颜色           0110                "Red"
*    0000          字的颜色           0111                "Orange"
*    0000          字的颜色           1000				 "Yellow"
*    0000          字的颜色           1001				 "Green"
*    0000          字的颜色           1010				 "Blue"
*    0000          字的颜色           1011				 "Violet"
*    0000          字的颜色           1100				 "Magenta"
*    0000          字的颜色           1101				 "Cyan"

*    0001          线的颜色           0000                "Black"
*    0001          线的颜色           0001                "Dark Gray"
*    0001          线的颜色           0010                "Gray"
*    0001          线的颜色           0011                "Light Gray"
*    0001          线的颜色           0100                "White"
*    0001          线的颜色           0101                "Brown"
*    0001          线的颜色           0110                "Red"
*    0001          线的颜色           0111                "Orange"
*    0001          线的颜色           1000				 "Yellow"
*    0001          线的颜色           1001				 "Green"
*    0001          线的颜色           1010				 "Blue"
*    0001          线的颜色           1011				 "Violet"
*    0001          线的颜色           1100				 "Magenta"
*    0001          线的颜色           1101				 "Cyan"

*    0010          文本框边框的颜色    0000                 "Black"
*    0010          文本框边框的颜色    0001                 "Dark Gray"
*    0010          文本框边框的颜色    0010                 "Gray"
*    0010          文本框边框的颜色    0011                 "Light Gray"
*    0010          文本框边框的颜色    0100                 "White"
*    0010          文本框边框的颜色    0101                 "Brown"
*    0010          文本框边框的颜色    0110                 "Red"
*    0010          文本框边框的颜色    0111                 "Orange"
*    0010          文本框边框的颜色    1000                 "Yellow"
*    0010          文本框边框的颜色    1001                 "Green"
*    0010          文本框边框的颜色    1010                 "Blue"
*    0010          文本框边框的颜色    1011                 "Violet"
*    0010          文本框边框的颜色    1100                 "Magenta"
*    0010          文本框边框的颜色    1101                 "Cyan"

*    0011          文本框填充的颜色    0000                 "Black"
*    0011          文本框填充的颜色    0001                 "Dark Gray"
*    0011          文本框填充的颜色    0010                 "Gray"
*    0011          文本框填充的颜色    0011                 "Light Gray"
*    0011          文本框填充的颜色    0100                 "White"
*    0011          文本框填充的颜色    0101                 "Brown"
*    0011          文本框填充的颜色    0110                 "Red"
*    0011          文本框填充的颜色    0111                 "Orange"
*    0011          文本框填充的颜色    1000                 "Yellow"
*    0011          文本框填充的颜色    1001                 "Green"
*    0011          文本框填充的颜色    1010                 "Blue"
*    0011          文本框填充的颜色    1011                 "Violet"
*    0011          文本框填充的颜色    1100                 "Magenta"
*    0011          文本框填充的颜色    1101                 "Cyan"

*/


typedef enum{FONT_COLOR=0,LINE_COLOR,TEXTBOXFRAME_COLOR,TEXTBOXFILL_COLOR} PROPERTY1;
void OutputSetting(int StyleName){
	int Property=0;
	for(Property=0;Property<=3;Property++){
	    PrintPrefix1();
	    printf("00");
	    printf("%d",StyleName);
	    printf("%s",DecimalToBinaryString(Property));

	    if(StyleName==1){
	    	switch (Property){
	    		case FONT_COLOR: printf("0100");
	    		break;
	    		case LINE_COLOR: printf("1010");
	    		break;
	    		case TEXTBOXFRAME_COLOR: printf("1010");
	    		break;
	    		case TEXTBOXFILL_COLOR: printf("1010");
	    		break;
	    	}
	    }
	}
	printf("\n");
}

/*
* 功能：    把当前加的线（落定线）转换成指令
* 落定线：  已经确定下来的线
* 用法：    记录线段起点(sx,sy)与长度向量(lx,ly) 
* 指令格式：
* (0000)  01    _sx_sy_lx_ly
* 指令前缀 指令名 线段起点(sx,sy)与长度向量(lx,ly) 
* 由于 高精度小数转换比较麻烦，且与直接编码几乎一致
* 故采用 直接打印 然后统一文件编码的方式
*/

void OutputLine(double sx,double sy,double lx,double ly){
	PrintPrefix0();

	printf("01");
	
	printf("_%ld_%ld_%ld_%ld\n",sx,sy,lx,ly);

}


/*
* 功能： 	  把当前的文本框转换成指令
* 用法：   记录当前文本框左下角坐标(x,y)与宽长数对(w,h)与当前文本框编号
* 指令格式： 
* (0000)     10          _x_y_w_h_Index
* 指令前缀   指令名      文本框左下角坐标(x,y)与宽长数对(w,h)
*/
void OutputTextBox(double x,double y,double w,double h,int Index){
	PrintPrefix0();

	printf("10");

	printf("_%ld_%ld_%ld_%ld_%d\n",x,y,w,h,Index);

}


/*
* 功能： 把当前输入文本框的字符转换成指令
* 用法： 记录当前文本框编号（自定义的，从一开始的，非UIID），输入还是删除，
* 如果是输入状态的话，记录 输入的字符是什么（Ascii 码整数）
* 如果是删除状态的话，记录 输入字符为$
* doi: delete/insert (0/1)
* 指令格式
(0000)   11        _Index_ch_doi
指令前缀  指令名      文本框编号 ascii码 删除或插入    
*/

void OutputAscii(int Index,int ch,int doi){
	PrintPrefix0();

	printf("11");

	printf("_%d_%c_%d",Index,(char)ch,doi);
}








