$NetBSD$

--- Telegram/lib_ui/ui/widgets/menu/menu_common.h.orig	2021-02-28 16:48:47.226690078 +0000
+++ Telegram/lib_ui/ui/widgets/menu/menu_common.h
@@ -6,6 +6,9 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
+#include "ui/ui_pch.h"
+
 namespace Ui::Menu {
 
 enum class TriggeredSource {
