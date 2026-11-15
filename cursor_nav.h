#ifndef CURSOR_NAV_H
#define CURSOR_NAV_H
#include "text_editor.h"
void moveCursorRight(TextEditor *e); void moveCursorLeft(TextEditor *e);
void moveCursorDown(TextEditor *e); void moveCursorUp(TextEditor *e);
void jumpToStartOfLine(TextEditor *e); void jumpToEndOfLine(TextEditor *e);
void jumpToStartOfFile(TextEditor *e); void jumpToEndOfFile(TextEditor *e);
void showCursorPosition(TextEditor *e);
#endif
