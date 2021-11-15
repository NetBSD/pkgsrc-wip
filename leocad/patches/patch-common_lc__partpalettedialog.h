$NetBSD$

Workaround for disabling PCH.

--- common/lc_partpalettedialog.h.orig	2021-06-05 23:41:42.000000000 +0000
+++ common/lc_partpalettedialog.h
@@ -1,5 +1,7 @@
 #pragma once
 
+#include "lc_global.h"
+
 namespace Ui {
 class lcPartPaletteDialog;
 }
