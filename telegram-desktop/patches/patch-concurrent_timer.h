$NetBSD$

--- Telegram/lib_base/base/concurrent_timer.h.orig	2020-02-14 22:40:43.318315127 +0000
+++ Telegram/lib_base/base/concurrent_timer.h
@@ -6,6 +6,7 @@
 //
 #pragma once
 
+#include "base/base_pch.h"
 #include "base/binary_guard.h"
 #include <crl/crl_time.h>
 #include <crl/crl_object_on_queue.h>
