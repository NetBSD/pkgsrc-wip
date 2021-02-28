$NetBSD$

--- Telegram/lib_ui/ui/main_queue_processor.h.orig	2021-02-28 19:12:54.602658465 +0000
+++ Telegram/lib_ui/ui/main_queue_processor.h
@@ -6,6 +6,9 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
+#include "ui/ui_pch.h"
+
 namespace Ui {
 
 class MainQueueProcessor : public QObject {
