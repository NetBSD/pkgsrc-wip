$NetBSD$

Workaround for disabling PCH.

--- qt/lc_qmodellistdialog.h.orig	2021-06-05 23:41:42.000000000 +0000
+++ qt/lc_qmodellistdialog.h
@@ -1,5 +1,6 @@
 #pragma once
 
+#include "lc_global.h"
 #include "lc_array.h"
 
 namespace Ui
