$NetBSD$

--- printing/print_settings.h.orig	2020-07-15 18:56:00.000000000 +0000
+++ printing/print_settings.h
@@ -1,4 +1,4 @@
-// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+/// Copyright (c) 2012 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
@@ -20,7 +20,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <map>
 
 #include "base/values.h"
@@ -69,7 +69,7 @@ class PRINTING_EXPORT PrintSettings {
     }
   };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
 #endif  // defined(OS_LINUX)
 
@@ -206,7 +206,7 @@ class PRINTING_EXPORT PrintSettings {
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
@@ -305,7 +305,7 @@ class PRINTING_EXPORT PrintSettings {
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
 #endif  // defined(OS_LINUX)
