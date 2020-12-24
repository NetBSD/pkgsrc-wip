$NetBSD$

Fix a warning when compiling on NetBSD (namely, use an int argument
for isspace instead of char).

--- src/tk/widget/input.c.orig	2020-12-17 02:23:41.000000000 +0000
+++ src/tk/widget/input.c
@@ -314,7 +314,7 @@ static int inp_key( Widget* inp, SDL_Key
             line_end = curr_line_start + inp_rangeFromWidth( inp, curr_line_start, -1 );
             if (inp->dat.inp.input[line_end] == '\0')
                next_line_start = SIZE_MAX;
-            else if (isspace(inp->dat.inp.input[line_end]))
+            else if (isspace((int)inp->dat.inp.input[line_end]))
                next_line_start = line_end + 1;
             else
                next_line_start = line_end;
