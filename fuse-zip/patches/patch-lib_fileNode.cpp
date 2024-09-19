$NetBSD: patch-lib_fileNode.cpp,v 1.1 2014/09/06 22:35:35 thomasklausner Exp $

Fix compilation issue.

--- lib/fileNode.cpp.orig	2014-01-14 16:55:27.000000000 +0000
+++ lib/fileNode.cpp
@@ -28,6 +28,10 @@
 #include <syslog.h>
 #include <cassert>
 
+#ifndef UINT16_MAX
+#define UINT16_MAX 0xffff
+#endif
+
 #include "fileNode.h"
 #include "extraField.h"
 
