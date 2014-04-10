$NetBSD: patch-src_mongo_shell_dbshell.cpp,v 1.1 2014/04/10 11:46:43 fhajny Exp $

Add support for NetBSD.
--- src/mongo/shell/dbshell.cpp.orig	2014-04-07 00:36:57.000000000 +0000
+++ src/mongo/shell/dbshell.cpp
@@ -62,7 +62,7 @@ bool gotInterrupted = false;
 bool inMultiLine = false;
 static volatile bool atPrompt = false; // can eval before getting to prompt
 
-#if !defined(__freebsd__) && !defined(__openbsd__) && !defined(_WIN32)
+#if !defined(__freebsd__) && !defined(__openbsd__) && !defined(__netbsd__) && !defined(_WIN32)
 // this is for ctrl-c handling
 #include <setjmp.h>
 jmp_buf jbuf;
