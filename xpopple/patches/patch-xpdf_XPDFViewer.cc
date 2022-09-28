$NetBSD$

Include XPM icon. Required for HAVE_X11_XPM_H.

--- xpdf/XPDFViewer.cc.orig	2022-09-28 11:53:00.000000000 +0000
+++ xpdf/XPDFViewer.cc
@@ -103,6 +103,9 @@
 // GUI includes
 //------------------------------------------------------------------------
 
+#ifdef HAVE_X11_XPM_H
+#include "xpdfIcon.xpm"
+#endif
 #include "leftArrow.xbm"
 #include "leftArrowDis.xbm"
 #include "dblLeftArrow.xbm"
