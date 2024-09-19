$NetBSD$

--- Telegram/lib_base/base/single_instance.h.orig	2020-02-16 20:34:20.023842921 +0000
+++ Telegram/lib_base/base/single_instance.h
@@ -6,6 +6,7 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
 #include "base/file_lock.h"
 
 #include <QtNetwork/QLocalServer>
