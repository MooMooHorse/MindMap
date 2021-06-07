# MindMap --VS code Edition
This can be directly opened by `VS code` text editor, built by `cmake` 

This is an interactive mind map, serving as C programming homework for MYZ's group.

All the implemented functions are as follows.

```

1. Add Line // when pressing add line button

0000 X1 Y1 X2 Y2

2. Add TextBox // when pressing add box button

0001 X1 Y1 W H

3. Add Text // when keyboard-entering one ascii character

0010 Index Ascii

4. Setting 

0011 0000 0000 (Textbox Frame Color)

0011 0001 1000 (Font Size)

0011 0010 0000 (Font Color)

0011 0011 0001 (Style)


5. Ignore

0100 LINENUMBEROFFSET

```

6. Clear

0101 



---

## Binary File

0) 导入 (没写)
 * 解析指令 维护4个数组


1) 按钮 
 *  生成 线 
	用法 选中一个文本框 然后点这个按钮 可以生成追随光标的线 然后再点下把线固定住 
 * 生成 文本框 
	用法 添加文本框至空余位置 （如果有多个空余位置 会从最近（时间上）空余的位置 到最早空余的位置顺序添加）

2） 维护
 * $FatherOfTextBox$ 数组 维护每个文本框父亲 向上跳得到深度 （没写，因为这是修改样式的）
 * $PositionOfTextBox$ 数组 维护每个文本框位置 
 * $PositionOfLine$ 数组 维护每条线的位置
 * $TextOfTextBox$ 数组 记录每个文本框内的字符
 * $StackForTextBox$ 栈 记录当前剩余放置文本框位置

3) 导出 （没写）

 * 每次对$PositionOf\_\_\_$ 数组进行写入的时候 记录一下指令

## Notes


1. 线可以被textbox覆盖，这样就直接从中心画就行了

2. 每个textbook 记录个father 这样每层就能分别设置样式

3. Textbox 函数自己写一下 返回一个结构体 

	（库不能改，那只好重写很多东西了




## BUG

一个bug 刚刚引进的 就是 增加了 mygui.c 这个复制的库，然后全局的函数就会 重复，这个需要改掉，
(1) 把mygui里面的重复全局函数去掉
(2) 自定义的函数改名字

## 增加功能
中文支持

(1) Escape 逃脱落定线
(2) Clear 清空 各种子程序里面的静态变量啊 什么能存的住的东西啊 全清零把。
(3) 按钮 Dark/Light Mode
(4) DefineColor() 函数增加颜色，这样就可以画出任意颜色
(5) 调节文本框大小按钮，点击后当鼠标进入一定区域规定鼠标为一个角的位置，由于中心确定，实际上文本框被鼠标唯一确定。
(6) 移动TextBox

focus mode

(7) 导入背景 个人以为不需要 最多调整背景颜色，这只需要每次先画个贼nm大的矩形就行了


## 三种风格 

* 从中间开始

* 从左边开始

* 双源




