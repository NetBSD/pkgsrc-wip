$NetBSD$

--- Telegram/lib_ui/ui/inactive_press.h.orig	2021-02-28 18:13:12.771439953 +0000
+++ Telegram/lib_ui/ui/inactive_press.h
@@ -6,6 +6,9 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
+#include "ui/ui_pch.h"
+
 namespace Ui {
 
 void MarkInactivePress(not_null<QWidget*> widget, bool was);
