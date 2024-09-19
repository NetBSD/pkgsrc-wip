$NetBSD$

--- Telegram/lib_storage/storage/storage_clear_legacy.h.orig	2020-02-17 23:45:45.124957617 +0000
+++ Telegram/lib_storage/storage/storage_clear_legacy.h
@@ -6,6 +6,8 @@
 //
 #pragma once
 
+#include "storage/storage_pch.h"
+
 namespace Storage {
 
 using CollectGoodFiles = Fn<void(FnMut<void(base::flat_set<QString>&&)>)>;
