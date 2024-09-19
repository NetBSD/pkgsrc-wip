$NetBSD$

--- Telegram/lib_base/base/object_ptr.h.orig	2021-02-28 15:15:14.754032642 +0000
+++ Telegram/lib_base/base/object_ptr.h
@@ -6,6 +6,9 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
+#include "ui/ui_pch.h"
+
 #include <QtCore/QPointer>
 
 // Smart pointer for QObject*, has move semantics, destroys object if it doesn't have a parent.
