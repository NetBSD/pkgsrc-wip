$NetBSD$
# Only define define MAP_ANONYMOUS when necessary
# PR: https://github.com/zorgnax/libtap/pull/33
--- tap/tap.c.orig	2018-04-16 23:43:28.000000000 +0000
+++ tap/tap.c
@@ -298,8 +298,12 @@ tap_end_todo () {
 #include <sys/param.h>
 #include <regex.h>
 
-#if defined __APPLE__ || defined BSD
+#ifndef MAP_ANONYMOUS
+#ifdef MAP_ANON
 #define MAP_ANONYMOUS MAP_ANON
+#else
+#error "System does not support mapping anonymous pages"
+#endif
 #endif
 
 /* Create a shared memory int to keep track of whether a piece of code executed
