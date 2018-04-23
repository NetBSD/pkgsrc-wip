$NetBSD$
# This enum has a symbol (UP) which conflicts with termcap.h
# https://github.com/pipeseroni/pipes.c/pull/25
--- src/pipe.c.orig	2018-04-16 23:07:46.000000000 +0000
+++ src/pipe.c
@@ -62,6 +62,13 @@ static size_t charwidth(const char *pipe
 //              Right    Down   Left    Up
 char states[][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
 
+enum DIRECTIONS {
+    RIGHT = 0,
+    DOWN = 1,
+    LEFT = 2,
+    UP = 3
+};
+
 const char * transition_char(char **list, int row, int col){
     return list[row * 4 + col];
 }
