$NetBSD$

Use results from configure scripts instead of dedicated conditions.

--- fltk/string.h.orig	2012-03-23 05:49:17.000000000 +0000
+++ fltk/string.h
@@ -45,6 +45,7 @@
 # include <string.h>
 # include <stdarg.h> /* for va_list */
 # include <stdio.h> /* for sprintf, vsprintf, snprintf and vsnprintf */
+# include <config.h>
 
 /* Windows has equivalent functions, but being Microsoft they added
    gratuitoius changes to the names to stop code from being portable: */
@@ -70,13 +71,17 @@ FL_API extern int strcasecmp(const char 
 FL_API extern int strncasecmp(const char *, const char *, size_t);
 #endif
 
-#if defined(DOXYGEN) || !defined(__linux) && !defined(_WIN32) && !defined(__FreeBSD__) && !defined(__APPLE__)
+#if !HAVE_SNPRINTF && defined(DOXYGEN)
 FL_API extern int snprintf(char *, size_t, const char *, ...);
+#endif
+#if !HAVE_VSNPRINTF && defined(DOXYGEN)
 FL_API extern int vsnprintf(char *, size_t, const char *, va_list ap);
 #endif
 
-#if defined(DOXYGEN) || !defined(__FreeBSD__) && !defined(__APPLE__)
+#if !HAVE_STRLCAT && defined(DOXYGEN)
 FL_API extern size_t strlcat(char *, const char *, size_t);
+#endif
+#if !HAVE_STRLCPY && defined(DOXYGEN)
 FL_API extern size_t strlcpy(char *, const char *, size_t);
 #endif
 
