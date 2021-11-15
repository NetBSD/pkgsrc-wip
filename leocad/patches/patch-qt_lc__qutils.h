$NetBSD$

Workaround for disabling PCH.

--- qt/lc_qutils.h.orig	2021-06-05 23:41:42.000000000 +0000
+++ qt/lc_qutils.h
@@ -1,5 +1,6 @@
 #pragma once
 
+#include "lc_global.h"
 #include <QObject>
 
 QString lcFormatValue(float Value, int Precision);
