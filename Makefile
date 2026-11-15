CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SRC=main.c text_editor.c text_ops.c cursor_nav.c redo_undo.c file_ops.c display_search.c
all: editor
editor: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o editor
clean:
	rm -f editor *.o
