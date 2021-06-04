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

```



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

	（库不能改，那只好重写很多东西了)
