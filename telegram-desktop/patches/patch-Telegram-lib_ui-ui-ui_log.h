$NetBSD$

--- Telegram/lib_ui/ui/ui_log.h.orig	2021-02-28 20:50:46.372569239 +0000
+++ Telegram/lib_ui/ui/ui_log.h
@@ -6,6 +6,9 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
+#include "ui/ui_pch.h"
+
 namespace Ui {
 
 void WriteLogEntry(const QString &message);
