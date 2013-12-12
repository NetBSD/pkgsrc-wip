$NetBSD: patch-src_stacktrace.h,v 1.1 2013/12/12 15:33:22 noud4 Exp $

Don't use execinfo on NetBSD.
Don't use stacktrace on NetBSD.

--- src/stacktrace.h.orig	2013-11-19 22:55:00.000000000 +0000
+++ src/stacktrace.h
@@ -6,7 +6,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#if !defined(Q_OS_NETBSD)
 #include <execinfo.h>
+#endif
 #include <cxxabi.h>
 
 /** Print a demangled stack backtrace of the caller function to FILE* out. */
@@ -14,6 +16,10 @@ static inline void print_stacktrace(FILE
 {
     fprintf(out, "stack trace:\n");
 
+#if defined(Q_OS_NETBSD)
+	fprintf(out, "  <empty, still todo>\n");
+	return;
+#else
     // storage array for stack trace address data
     void* addrlist[max_frames+1];
 
@@ -89,6 +95,7 @@ static inline void print_stacktrace(FILE
 
     free(funcname);
     free(symbollist);
+#endif
 }
 
 #endif // _STACKTRACE_H_
