$NetBSD$

--- chrome/browser/flag_descriptions.h.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/flag_descriptions.h
@@ -19,7 +19,7 @@
 #include "ppapi/buildflags/buildflags.h"
 #include "printing/buildflags/buildflags.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif  // defined(OS_LINUX)
 
@@ -2390,7 +2390,7 @@ extern const char kEnableNewBadgeOnMenuI
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 extern const char kWebGL2ComputeContextName[];
 extern const char kWebGL2ComputeContextDescription[];
@@ -2398,7 +2398,7 @@ extern const char kWebGL2ComputeContextD
 #endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 
 extern const char kEnableMediaFeedsName[];
 extern const char kEnableMediaFeedsDescription[];
@@ -2418,7 +2418,7 @@ extern const char kRemoteCopyProgressNot
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kDirectManipulationStylusName[];
 extern const char kDirectManipulationStylusDescription[];
