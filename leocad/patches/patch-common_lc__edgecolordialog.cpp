$NetBSD$

Workaround for disabling PCH.

--- common/lc_edgecolordialog.cpp.orig	2021-11-11 11:23:54.023876623 +0000
+++ common/lc_edgecolordialog.cpp
@@ -1,3 +1,4 @@
+#include "lc_global.h"
 #include "lc_edgecolordialog.h"
 #include "lc_application.h"
 
