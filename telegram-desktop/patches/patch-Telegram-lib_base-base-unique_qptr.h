$NetBSD$

--- Telegram/lib_base/base/unique_qptr.h.orig	2021-02-28 12:09:26.827342516 +0000
+++ Telegram/lib_base/base/unique_qptr.h
@@ -8,6 +8,8 @@
 
 #include <QtCore/QPointer>
 
+#include "base/base_pch.h"
+
 namespace base {
 
 template <typename T>
