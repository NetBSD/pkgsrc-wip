$NetBSD$

--- source/lib/secure_crt.cpp.orig	2022-08-21 14:45:19.000000000 +0200
+++ source/lib/secure_crt.cpp	2023-05-03 23:36:26.329771228 +0200
@@ -113,7 +113,7 @@
 // self-test and the t* defines (needed for test).
 #if EMULATE_SECURE_CRT
 
-#if !OS_UNIX || OS_MACOSX || OS_OPENBSD
+#if !OS_UNIX || OS_MACOSX || OS_OPENBSD || defined(__NetBSD__) /* XXX: Add wcsnlen(3) in NetBSD */
 // return length [in characters] of a string, not including the trailing
 // null character. to protect against access violations, only the
 // first <max_len> characters are examined; if the null character is
