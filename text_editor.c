#include <stdlib.h>
#include <string.h>
#include "text_editor.h"
int initializeEditor(TextEditor *e) {
 if (!e) return 0;
 memset(e,0,sizeof(*e));
 e->cursorLine=1;
 e->recordingHistory=1;
 if (!initializeStack(&e->undoStack)) return 0;
 if (!initializeStack(&e->redoStack)) { freeStack(&e->undoStack); return 0; }
 return 1;
}
void destroyEditor(TextEditor *e) {
 Node *n,*next; if(!e)return;
 for(n=e->head;n;n=next){next=n->next;free(n->line);free(n);}
 free(e->clipboard); freeStack(&e->undoStack); freeStack(&e->redoStack); memset(e,0,sizeof(*e));
}
