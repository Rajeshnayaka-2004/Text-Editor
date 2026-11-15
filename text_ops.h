#ifndef TEXT_OPS_H
#define TEXT_OPS_H
#include "text_editor.h"
Node *createNode(const char *s);
int insertLine(TextEditor *e, const char *s);
int insertLineAtPosition(TextEditor *e, const char *s, int line);
int deleteLine(TextEditor *e, int line);
void displayText(TextEditor *e);
int insertCharacters(TextEditor *e, int line, int pos, const char *s);
int deleteCharacters(TextEditor *e, int line, int pos, int count);
char *copyText(TextEditor *e, int line, int pos, int count);
char *cutText(TextEditor *e, int line, int pos, int count);
int pasteText(TextEditor *e, int line, int pos, const char *s);
#endif
