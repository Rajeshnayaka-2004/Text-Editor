#ifndef REDO_UNDO_H
#define REDO_UNDO_H
typedef enum { INSERT_ACTION, DELETE_ACTION, INSERT_LINE_ACTION, DELETE_LINE_ACTION } OperationType;
typedef struct { OperationType operation; int lineNumber; int position; char *text; } Action;
typedef struct { Action *actions; int size; int capacity; } DynamicArrayStack;
int initializeStack(DynamicArrayStack *s);
int pushStack(DynamicArrayStack *s, Action a);
int popStack(DynamicArrayStack *s, Action *a);
void clearStack(DynamicArrayStack *s);
void freeStack(DynamicArrayStack *s);
struct TextEditor;
int undo(struct TextEditor *e);
int redo(struct TextEditor *e);
#endif
