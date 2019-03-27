$NetBSD$

--- general.h.orig	2016-11-23 09:52:52.000000000 +0000
+++ general.h
@@ -57,11 +57,11 @@
  *  to prevent warnings about unused variables.
  */
 #if (__GNUC__ > 2  ||  (__GNUC__ == 2  &&  __GNUC_MINOR__ >= 7)) && !defined (__GNUG__)
-# define __unused__  __attribute__((unused))
-# define __printf__(s,f)  __attribute__((format (printf, s, f)))
+# define CTAGS_UNUSED  __attribute__((unused))
+# define CTAGS_PRINTF(s,f)  __attribute__((format (printf, s, f)))
 #else
-# define __unused__
-# define __printf__(s,f)
+# define CTAGS_UNUSED
+# define CTAGS_PRINTF(s,f)
 #endif
 
 /*
