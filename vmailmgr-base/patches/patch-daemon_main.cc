$NetBSD$

Remove unused function.

--- daemon/main.cc.orig	2024-02-22 18:32:57.270441623 +0000
+++ daemon/main.cc
@@ -61,12 +61,6 @@ cli_option cli_options[] = {
 
 #define TIMEOUT 1
 
-static inline void die(const char* msg)
-{
-  perror(msg);
-  exit(1);
-}
-
 static void finishreq()
 {
   alarm(0);
