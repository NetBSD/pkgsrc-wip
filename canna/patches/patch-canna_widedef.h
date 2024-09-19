$NetBSD: patch-ae,v 1.1 2005/12/29 15:29:12 joerg Exp $

DragonFly wchar_t support.

--- canna/widedef.h.orig	2003-12-27 17:15:20.000000000 +0000
+++ canna/widedef.h
@@ -36,7 +36,10 @@
 # include <machine/ansi.h>
 #endif
 
-#if (defined(__FreeBSD__) && __FreeBSD_version < 500000) \
+#if defined(__DragonFly__)
+# include <wchar.h>
+# define _WCHAR_T
+#elif (defined(__FreeBSD__) && __FreeBSD_version < 500000) \
     || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
 # ifdef _BSD_WCHAR_T_
 #  undef _BSD_WCHAR_T_
