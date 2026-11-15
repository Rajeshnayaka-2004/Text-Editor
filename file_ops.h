#ifndef FILE_OPS_H
#define FILE_OPS_H
#include "text_editor.h"
int openFile(TextEditor *e, const char *filename);
int saveFile(TextEditor *e, const char *filename);
void closeFile(TextEditor *e);
#endif
