#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_ops.h"
#include "text_ops.h"
#include "redo_undo.h"
int saveFile(TextEditor*e,const char*name){FILE*f;Node*p;if(!e||!name||(f=fopen(name,"w"))==NULL)return 0;for(p=e->head;p;p=p->next)if(fprintf(f,"%s\n",p->line)<0){fclose(f);return 0;}return fclose(f)==0;}
void closeFile(TextEditor*e){Node*p,*next;if(!e)return;for(p=e->head;p;p=next){next=p->next;free(p->line);free(p);}e->head=e->tail=e->cursor=NULL;e->cursorLine=1;e->cursorPos=0;}
int openFile(TextEditor*e,const char*name){FILE*f;char buf[4096];TextEditor temp;int flag;if(!e||!name||(f=fopen(name,"r"))==NULL)return 0;memset(&temp,0,sizeof(temp));temp.recordingHistory=0;while(fgets(buf,sizeof(buf),f)){size_t n=strlen(buf);if(n&&buf[n-1]=='\n')buf[--n]='\0';if(!insertLine(&temp,buf)){fclose(f);closeFile(&temp);return 0;}}if(ferror(f)){fclose(f);closeFile(&temp);return 0;}fclose(f);flag=e->recordingHistory;e->recordingHistory=0;closeFile(e);e->head=temp.head;e->tail=temp.tail;e->cursor=e->head;e->cursorLine=1;e->cursorPos=0;temp.head=temp.tail=temp.cursor=NULL;e->recordingHistory=flag;clearStack(&e->undoStack);clearStack(&e->redoStack);return 1;}
