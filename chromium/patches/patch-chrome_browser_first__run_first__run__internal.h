$NetBSD$

--- chrome/browser/first_run/first_run_internal.h.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/first_run/first_run_internal.h
@@ -64,7 +64,7 @@ FirstRunState DetermineFirstRunState(boo
                                      bool force_first_run,
                                      bool no_first_run);
 
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
