$NetBSD$

--- source/lib/secure_crt.cpp.orig	2015-01-24 00:22:12.000000000 +0000
+++ source/lib/secure_crt.cpp
@@ -112,7 +112,7 @@ STATUS_ADD_DEFINITIONS(secureCrtStatusDe
 // self-test and the t* defines (needed for test).
 #if EMULATE_SECURE_CRT
 
-#if !OS_UNIX || OS_MACOSX || OS_OPENBSD
+#if !OS_UNIX || OS_MACOSX || OS_OPENBSD || defined(__NetBSD__) /* XXX: Add wcsnlen(3) in NetBSD */
 // return length [in characters] of a string, not including the trailing
 // null character. to protect against access violations, only the
 // first <max_len> characters are examined; if the null character is
