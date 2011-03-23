$NetBSD: patch-src_gui_autorecover.cpp,v 1.1 2011/03/23 04:37:07 phonohawk Exp $

Fix breakage on NetBSD/amd64 and possibly other NetBSD platforms.

--- src/gui/autorecover.cpp.orig	2011-03-23 02:11:25.000000000 +0000
+++ src/gui/autorecover.cpp
@@ -32,6 +32,7 @@
 
 #include "autorecover.h"
 
+#include <errno.h>
 #ifdef HAVE_SYS_ERRNO_H
 #include <sys/errno.h>
 #endif
