$NetBSD$
# Add a CPIPES_ prefix to each member of the DIRECTIONS enum to prevent termcap.h conflict
# Fixed upstream awaiting new release: https://github.com/pipeseroni/pipes.c/pull/25
--- src/pipe.h.orig	2018-04-16 23:07:46.000000000 +0000
+++ src/pipe.h
@@ -26,10 +26,10 @@ struct pipe {
 };
 
 enum DIRECTIONS {
-    RIGHT = 0,
-    DOWN = 1,
-    LEFT = 2,
-    UP = 3
+    CPIPES_RIGHT = 0,
+    CPIPES_DOWN = 1,
+    CPIPES_LEFT = 2,
+    CPIPES_UP = 3
 };
 struct palette;
 
