$NetBSD$

Include XPM icon. Required for HAVE_X11_XPM_H.

--- xpdf/XPDFViewer.cc.orig	2026-02-09 10:22:46.000000000 +0000
+++ xpdf/XPDFViewer.cc
@@ -103,6 +103,9 @@
 #endif
 
 //------------------------------------------------------------------------
+#ifdef HAVE_X11_XPM_H
+#include "xpdfIcon.xpm"
+#endif
 // GUI includes
 //------------------------------------------------------------------------
 
