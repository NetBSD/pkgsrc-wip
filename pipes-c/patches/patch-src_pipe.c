$NetBSD$
# Add a CPIPES_ prefix to each member of the DIRECTIONS enum to prevent termcap.h conflict
# Fixed upstream awaiting new release: https://github.com/pipeseroni/pipes.c/pull/25
--- src/pipe.c.orig	2018-04-16 23:07:46.000000000 +0000
+++ src/pipe.c
@@ -266,20 +266,20 @@ void assign_matrices(char *pipe_chars,
                 break;
             // Transition chars go ┓,┛,┗,┏
             case 2:
-                transition[RIGHT * 4 + DOWN] = c;
-                transition[UP * 4 + LEFT] = c;
+                transition[CPIPES_RIGHT * 4 + CPIPES_DOWN] = c;
+                transition[CPIPES_UP * 4 + CPIPES_LEFT] = c;
                 break;
             case 3:
-                transition[RIGHT * 4 + UP] = c;
-                transition[DOWN * 4 + LEFT] = c;
+                transition[CPIPES_RIGHT * 4 + CPIPES_UP] = c;
+                transition[CPIPES_DOWN * 4 + CPIPES_LEFT] = c;
                 break;
             case 4:
-                transition[LEFT * 4 + UP] = c;
-                transition[DOWN * 4 + RIGHT] = c;
+                transition[CPIPES_LEFT * 4 + CPIPES_UP] = c;
+                transition[CPIPES_DOWN * 4 + CPIPES_RIGHT] = c;
                 break;
             case 5:
-                transition[LEFT * 4 + DOWN] = c;
-                transition[UP * 4 + RIGHT] = c;
+                transition[CPIPES_LEFT * 4 + CPIPES_DOWN] = c;
+                transition[CPIPES_UP * 4 + CPIPES_RIGHT] = c;
                 break;
             default:
                 // No way to reach here.
