$NetBSD$

Workaround for disabling PCH.

--- common/lc_mainwindow.h.orig	2021-11-11 11:39:22.401904813 +0000
+++ common/lc_mainwindow.h
@@ -1,5 +1,5 @@
 #pragma once
-
+#include "lc_global.h"
 #include "lc_application.h"
 #include "lc_shortcuts.h"
 #include "lc_array.h"
