$NetBSD$

fix for PR pkg/45392

--- src/3rdparty/dxflib/src/dl_writer.h.orig	2016-06-30 12:42:57.000000000 +0000
+++ src/3rdparty/dxflib/src/dl_writer.h
@@ -36,6 +36,7 @@
 #pragma once
 #endif // _MSC_VER > 1000

+#include <cstring>
 #include <iostream>
 #include <algorithm>
