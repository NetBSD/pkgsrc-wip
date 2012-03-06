$NetBSD: patch-src_nodecontroller.h,v 1.1 2012/03/06 23:48:46 minskim Exp $

--- src/nodecontroller.h.orig	2012-03-06 23:45:28.000000000 +0000
+++ src/nodecontroller.h
@@ -34,6 +34,16 @@
 #  include <python2.2/Python.h>
 #elif HAVE_PYTHON2_3
 #  include <python2.3/Python.h>
+#elif HAVE_PYTHON2_4
+#  include <python2.4/Python.h>
+#elif HAVE_PYTHON2_5
+#  include <python2.5/Python.h>
+#elif HAVE_PYTHON2_6
+#  include <python2.6/Python.h>
+#elif HAVE_PYTHON2_7
+#  include <python2.7/Python.h>
+#elif HAVE_PYTHON3_1
+#  include <python3.1/Python.h>
 #endif
 
 #include "common.h"
