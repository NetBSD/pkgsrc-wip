$NetBSD: patch-shell__dbshell.cpp,v 1.3 2012/10/02 08:48:46 fhajny Exp $

Add support for NetBSD.
--- src/mongo/shell/dbshell.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/shell/dbshell.cpp
@@ -51,7 +51,7 @@ bool inMultiLine = false;
 static volatile bool atPrompt = false; // can eval before getting to prompt
 bool autoKillOp = false;
 
-#if !defined(__freebsd__) && !defined(__openbsd__) && !defined(_WIN32)
+#if !defined(__freebsd__) && !defined(__openbsd__) && !defined(__netbsd__) && !defined(_WIN32)
 // this is for ctrl-c handling
 #include <setjmp.h>
 jmp_buf jbuf;
