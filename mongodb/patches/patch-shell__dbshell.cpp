$NetBSD: patch-shell__dbshell.cpp,v 1.1 2012/02/22 11:36:27 bartoszkuzma Exp $

--- shell/dbshell.cpp.orig	2011-12-14 17:18:48.000000000 +0000
+++ shell/dbshell.cpp
@@ -44,7 +44,7 @@ static volatile bool atPrompt = false; /
 bool autoKillOp = false;
 
 
-#if defined(USE_LINENOISE) && !defined(__freebsd__) && !defined(__openbsd__) && !defined(_WIN32)
+#if defined(USE_LINENOISE) && !defined(__freebsd__) && !defined(__netbsd) && !defined(__openbsd__) && !defined(_WIN32)
 // this is for ctrl-c handling
 #include <setjmp.h>
 jmp_buf jbuf;
