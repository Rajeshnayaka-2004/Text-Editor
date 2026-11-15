#include <stdlib.h>
#include <string.h>
#include "redo_undo.h"
#include "text_editor.h"
#include "text_ops.h"
int initializeStack(DynamicArrayStack *s){if(!s)return 0;s->size=0;s->capacity=8;s->actions=malloc(sizeof(Action)*8);if(!s->actions){s->capacity=0;return 0;}return 1;}
int pushStack(DynamicArrayStack *s,Action a){Action *t;char *c=NULL;if(!s)return 0;if(!s->actions&&!initializeStack(s))return 0;if(a.text){c=malloc(strlen(a.text)+1);if(!c)return 0;strcpy(c,a.text);}if(s->size==s->capacity){int cap=s->capacity*2;t=realloc(s->actions,sizeof(Action)*cap);if(!t){free(c);return 0;}s->actions=t;s->capacity=cap;}a.text=c;s->actions[s->size++]=a;return 1;}
int popStack(DynamicArrayStack *s,Action *a){if(!s||!a||!s->size)return 0;*a=s->actions[--s->size];s->actions[s->size].text=NULL;return 1;}
void clearStack(DynamicArrayStack *s){int i;if(!s)return;for(i=0;i<s->size;i++)free(s->actions[i].text);s->size=0;}
void freeStack(DynamicArrayStack *s){if(!s)return;clearStack(s);free(s->actions);s->actions=NULL;s->capacity=0;}
static int apply(TextEditor *e,Action *a,int reverse){int ok=0,flag=e->recordingHistory;e->recordingHistory=0;
 switch(a->operation){case INSERT_ACTION:ok=reverse?deleteCharacters(e,a->lineNumber,a->position+1,(int)strlen(a->text)):insertCharacters(e,a->lineNumber,a->position+1,a->text);break;
 case DELETE_ACTION:ok=reverse?insertCharacters(e,a->lineNumber,a->position+1,a->text):deleteCharacters(e,a->lineNumber,a->position+1,(int)strlen(a->text));break;
 case INSERT_LINE_ACTION:ok=reverse?deleteLine(e,a->lineNumber):insertLineAtPosition(e,a->text,a->lineNumber);break;
 case DELETE_LINE_ACTION:ok=reverse?insertLineAtPosition(e,a->text,a->lineNumber):deleteLine(e,a->lineNumber);break;}
 e->recordingHistory=flag;return ok;}
int undo(TextEditor *e){Action a;if(!e||!popStack(&e->undoStack,&a))return 0;if(!apply(e,&a,1)){pushStack(&e->undoStack,a);free(a.text);return 0;}if(!pushStack(&e->redoStack,a)){free(a.text);return 0;}free(a.text);return 1;}
int redo(TextEditor *e){Action a;if(!e||!popStack(&e->redoStack,&a))return 0;if(!apply(e,&a,0)){pushStack(&e->redoStack,a);free(a.text);return 0;}if(!pushStack(&e->undoStack,a)){free(a.text);return 0;}free(a.text);return 1;}
