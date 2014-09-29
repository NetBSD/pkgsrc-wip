$NetBSD: patch-intl_hyphenation_hnjalloc.h,v 1.1 2014/09/29 10:46:24 thomasklausner Exp $

--- intl/hyphenation/hnjalloc.h.orig	2014-09-28 08:30:01.000000000 +0000
+++ intl/hyphenation/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
