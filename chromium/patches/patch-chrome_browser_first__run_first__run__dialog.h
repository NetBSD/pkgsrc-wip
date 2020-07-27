$NetBSD$

--- chrome/browser/first_run/first_run_dialog.h.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/first_run/first_run_dialog.h
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 
 // Hide this function on platforms where the dialog does not exist.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 
 class Profile;
 
