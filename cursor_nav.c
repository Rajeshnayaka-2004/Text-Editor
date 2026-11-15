#include <stdio.h>
#include <string.h>
#include "cursor_nav.h"
static int length(Node*n){return n?(int)strlen(n->line):0;}
void moveCursorRight(TextEditor*e){if(e&&e->cursor&&e->cursorPos<length(e->cursor))e->cursorPos++;}
void moveCursorLeft(TextEditor*e){if(e&&e->cursor&&e->cursorPos>0)e->cursorPos--;}
void moveCursorDown(TextEditor*e){if(e&&e->cursor&&e->cursor->next){e->cursor=e->cursor->next;e->cursorLine++;if(e->cursorPos>length(e->cursor))e->cursorPos=length(e->cursor);}}
void moveCursorUp(TextEditor*e){if(e&&e->cursor&&e->cursor->prev){e->cursor=e->cursor->prev;e->cursorLine--;if(e->cursorPos>length(e->cursor))e->cursorPos=length(e->cursor);}}
void jumpToStartOfLine(TextEditor*e){if(e&&e->cursor)e->cursorPos=0;}
void jumpToEndOfLine(TextEditor*e){if(e&&e->cursor)e->cursorPos=length(e->cursor);}
void jumpToStartOfFile(TextEditor*e){if(e){e->cursor=e->head;e->cursorLine=1;e->cursorPos=0;}}
void jumpToEndOfFile(TextEditor*e){Node*p;if(!e)return;e->cursor=e->tail;e->cursorLine=1;for(p=e->head;p&&p!=e->tail;p=p->next)e->cursorLine++;e->cursorPos=length(e->tail);}
void showCursorPosition(TextEditor*e){if(e)printf("Cursor line: %d, character position: %d\n",e->cursorLine,e->cursorPos);}
