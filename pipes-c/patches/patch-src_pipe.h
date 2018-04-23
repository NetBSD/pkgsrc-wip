$NetBSD$
# This enum has a symbol (UP) which conflicts with termcap.h
# https://github.com/pipeseroni/pipes.c/pull/25
--- src/pipe.h.orig	2018-04-16 23:07:46.000000000 +0000
+++ src/pipe.h
@@ -25,12 +25,6 @@ struct pipe {
     int x, y;
 };
 
-enum DIRECTIONS {
-    RIGHT = 0,
-    DOWN = 1,
-    LEFT = 2,
-    UP = 3
-};
 struct palette;
 
 void init_pipe(struct pipe *pipe, struct palette *palette,
