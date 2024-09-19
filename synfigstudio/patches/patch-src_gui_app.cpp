$NetBSD: patch-src_gui_app.cpp,v 1.1 2011/03/23 04:37:07 phonohawk Exp $

Fix breakage on NetBSD/amd64 and possibly other NetBSD platforms.

--- src/gui/app.cpp.orig	2011-03-23 01:36:43.000000000 +0000
+++ src/gui/app.cpp
@@ -43,6 +43,7 @@
 #include <locale>
 #include <cstring>
 
+#include <errno.h>
 #ifdef HAVE_SYS_ERRNO_H
 #include <sys/errno.h>
 #endif
