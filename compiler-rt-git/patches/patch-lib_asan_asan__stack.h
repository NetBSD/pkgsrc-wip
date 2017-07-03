$NetBSD$

--- lib/asan/asan_stack.h.orig	2017-07-03 15:33:06.523226694 +0000
+++ lib/asan/asan_stack.h
@@ -44,7 +44,7 @@ void GetStackTraceWithPcBpAndContext(Buf
       // On FreeBSD the slow unwinding that leverages _Unwind_Backtrace()
       // yields the call stack of the signal's handler and not of the code
       // that raised the signal (as it does on Linux).
-      if (SANITIZER_FREEBSD && t->isInDeadlySignal()) fast = true;
+      if ((SANITIZER_FREEBSD || SANITIZER_NETBSD) && t->isInDeadlySignal()) fast = true;
       uptr stack_top = t->stack_top();
       uptr stack_bottom = t->stack_bottom();
       ScopedUnwinding unwind_scope(t);
