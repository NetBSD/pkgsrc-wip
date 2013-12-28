$NetBSD: patch-lib_notmuch-private.h,v 1.1 2013/12/28 16:42:40 thomasklausner Exp $

Doesn't compile with clang.

--- lib/notmuch-private.h.orig	2013-08-03 11:29:40.000000000 +0000
+++ lib/notmuch-private.h
@@ -64,7 +64,7 @@ NOTMUCH_BEGIN_DECLS
 #define unused(x) x __attribute__ ((unused))
 
 #ifdef __cplusplus
-# define visible __attribute__((visibility("default")))
+# define visible
 #else
 # define visible
 #endif
