$NetBSD$

--- Telegram/lib_base/base/runtime_composer.h.orig	2020-02-16 20:18:51.907563863 +0000
+++ Telegram/lib_base/base/runtime_composer.h
@@ -5,6 +5,7 @@
 // https://github.com/desktop-app/legal/blob/master/LEGAL
 //
 #pragma once
+#include "base/base_pch.h"
 
 template <typename Base>
 class RuntimeComposer;
