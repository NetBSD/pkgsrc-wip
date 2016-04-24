$NetBSD$

--- src/pal/src/exception/seh-unwind.cpp.orig	2016-04-08 23:29:23.000000000 +0000
+++ src/pal/src/exception/seh-unwind.cpp
@@ -226,7 +226,7 @@ BOOL PAL_VirtualUnwind(CONTEXT *context,
     unw_context_t unwContext;
     unw_cursor_t cursor;
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(_ARM64_) || defined(_ARM_)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(_ARM64_) || defined(_ARM_)
     DWORD64 curPc;
 #endif
 
@@ -262,7 +262,7 @@ BOOL PAL_VirtualUnwind(CONTEXT *context,
     WinContextToUnwindCursor(context, &cursor);
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(_ARM64_) || defined(_ARM_)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)  || defined(_ARM64_) || defined(_ARM_)
     // OSX and FreeBSD appear to do two different things when unwinding
     // 1: If it reaches where it cannot unwind anymore, say a 
     // managed frame.  It wil return 0, but also update the $pc
@@ -295,7 +295,7 @@ BOOL PAL_VirtualUnwind(CONTEXT *context,
     // Update the passed in windows context to reflect the unwind
     //
     UnwindContextToWinContext(&cursor, context);
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(_ARM64_) || defined(_ARM_)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)  || defined(_ARM64_) || defined(_ARM_)
     if (st == 0 && CONTEXTGetPC(context) == curPc)
     {
         CONTEXTSetPC(context, 0);
