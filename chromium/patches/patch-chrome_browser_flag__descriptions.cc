$NetBSD$

--- chrome/browser/flag_descriptions.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/flag_descriptions.cc
@@ -4080,7 +4080,7 @@ const char kEnableNewBadgeOnMenuItemsDes
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 const char kWebGL2ComputeContextName[] = "WebGL 2.0 Compute";
 const char kWebGL2ComputeContextDescription[] =
@@ -4123,7 +4123,7 @@ const char kRemoteCopyProgressNotificati
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
@@ -4140,7 +4140,7 @@ const char kWebContentsOcclusionDescript
 
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_TCMALLOC)
 const char kDynamicTcmallocName[] = "Dynamic Tcmalloc Tuning";
 const char kDynamicTcmallocDescription[] =
