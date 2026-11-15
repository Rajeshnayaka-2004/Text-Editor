#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#include "redo_undo.h"
typedef struct Node { char *line; struct Node *prev, *next; } Node;
typedef struct TextEditor {
 Node *head, *tail, *cursor;
 int cursorLine, cursorPos; /* line is 1-based; character position is 0-based */
 char *clipboard;
 DynamicArrayStack undoStack, redoStack;
 int recordingHistory;
} TextEditor;
int initializeEditor(TextEditor *e);
void destroyEditor(TextEditor *e);
#endif
