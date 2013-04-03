$NetBSD: patch-src_util_check.h,v 1.1 2013/04/03 21:21:05 outpaddling Exp $

--- src/util/check.h.orig	2013-04-03 21:02:05.000000000 +0000
+++ src/util/check.h
@@ -33,6 +33,7 @@ extern void check_breakpoint(void);
 #define CHECK_BREAKPOINT /* nothing */
 #endif
 
+#ifdef HAVE_MPI
 #define CHECK(condition, message) do { \
      if (!(condition))  { \
           CHECK_BREAKPOINT; \
@@ -40,6 +41,14 @@ extern void check_breakpoint(void);
 		  message "\n", __LINE__); \
      } \
 } while (0)
+#else
+extern void scm_mpb_error (const char *file, int line, const char *message);
+#define CHECK(condition, message) \
+     if (!(condition))  { \
+          CHECK_BREAKPOINT; \
+          scm_mpb_error(__FILE__, __LINE__, message); \
+     }
+#endif
 
 #endif /* not CHECK_DISABLE */
 
