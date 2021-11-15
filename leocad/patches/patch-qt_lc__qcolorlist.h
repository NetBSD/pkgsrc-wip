$NetBSD$

Workaround for disabling PCH.

--- qt/lc_qcolorlist.h.orig	2021-06-05 23:41:42.000000000 +0000
+++ qt/lc_qcolorlist.h
@@ -1,5 +1,7 @@
 #pragma once
 
+#include "lc_global.h"
+
 struct lcColorListCell
 {
 	QRect Rect;
