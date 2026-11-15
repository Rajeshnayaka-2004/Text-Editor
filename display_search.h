#ifndef DISPLAY_SEARCH_H
#define DISPLAY_SEARCH_H
#include "text_editor.h"
void findText(TextEditor *e, const char *word);
int replaceText(TextEditor *e, const char *oldText, const char *newText);
#endif
