$NetBSD$

Include XPM icon. Required for HAVE_X11_XPM_H.
Include "PDFDoc.h" early to avoid namespace clash with X11 macro "None":

/usr/pkgsrc/work/wip/xpopple/work/.buildlink/include/X11/X.h:115:30: error: expected identifier before numeric constant
  115 | #define None                 0L /* universal null resource or null atom */
      |                              ^~
/usr/pkgsrc/work/wip/xpopple/work/.buildlink/include/poppler/XRef.h:104:5: note: in expansion of macro 'None'
  104 |     None, /* No compression */
      |     ^~~~

--- xpdf/XPDFViewer.cc.orig	2024-04-22 14:53:38.000000000 +0000
+++ xpdf/XPDFViewer.cc
@@ -11,6 +11,8 @@
 
 #include <poppler-config.h>
 
+#include "PDFDoc.h"
+
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
@@ -33,7 +35,6 @@
 #include "Error.h"
 #include "GlobalParams.h"
 #include "XPDFParams.h"
-#include "PDFDoc.h"
 #include "Link.h"
 #include "ErrorCodes.h"
 #include "Outline.h"
@@ -103,6 +104,9 @@
 // GUI includes
 //------------------------------------------------------------------------
 
+#ifdef HAVE_X11_XPM_H
+#include "xpdfIcon.xpm"
+#endif
 #include "leftArrow.xbm"
 #include "leftArrowDis.xbm"
 #include "dblLeftArrow.xbm"
