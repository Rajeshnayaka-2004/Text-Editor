# Console-Based Text Editor (C)

Features: doubly linked list line storage, insert/delete lines and characters, cursor navigation, search/replace, copy/cut/paste, file open/save, and undo/redo.

Build: `make`

Run: `./editor`

Direct build: `gcc -Wall -Wextra -std=c99 main.c text_editor.c text_ops.c cursor_nav.c redo_undo.c file_ops.c display_search.c -o editor`

Line numbers and edit positions are 1-based. Cursor character positions are 0-based. Search is case-sensitive.
