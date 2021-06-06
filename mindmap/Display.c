#include "Display.h"
#include "Line.h"
#include "ButtonRelated.h"
#include "TextBox.h"
#include "graphics.h"

void display()
{
	DisplayClear();

	DrawButton();

	DrawLines();

	DrawTextBox();

}