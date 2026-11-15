#include <stdio.h>
#include <string.h>
#include "display_search.h"
#include "text_ops.h"
void findText(TextEditor*e,const char*w){Node*n;int line=1,found=0;if(!e||!w||!*w){puts("Invalid search text.");return;}for(n=e->head;n;n=n->next,line++){char*p=n->line;while((p=strstr(p,w))!=NULL){printf("Found at line %d, position %ld\n",line,(long)(p-n->line+1));found++;p++;}}if(!found)puts("Text not found.");}
int replaceText(TextEditor*e,const char*old,const char*newText){Node*n;int line=1,total=0;size_t olen,nlen;if(!e||!old||!newText||!*old)return 0;olen=strlen(old);nlen=strlen(newText);for(n=e->head;n;n=n->next,line++){size_t offset=0;while(1){char*m=strstr(n->line+offset,old);size_t index;if(!m)break;index=(size_t)(m-n->line);if(!deleteCharacters(e,line,(int)index+1,(int)olen))return total;if(!insertCharacters(e,line,(int)index+1,newText))return total;total++;offset=index+nlen;}}return total;}
