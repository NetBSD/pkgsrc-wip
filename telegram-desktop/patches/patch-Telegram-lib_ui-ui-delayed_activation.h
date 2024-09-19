$NetBSD$

--- Telegram/lib_ui/ui/delayed_activation.h.orig	2021-02-28 17:44:56.030377067 +0000
+++ Telegram/lib_ui/ui/delayed_activation.h
@@ -6,6 +6,9 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
+#include "ui/ui_pch.h"
+
 namespace Ui {
 
 void ActivateWindowDelayed(not_null<QWidget*> widget);
