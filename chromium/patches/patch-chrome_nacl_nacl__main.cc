$NetBSD: patch-chrome_nacl_nacl__main.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/nacl/nacl_main.cc.orig	2011-04-13 08:01:59.000000000 +0000
+++ chrome/nacl/nacl_main.cc
@@ -114,7 +114,7 @@ int NaClMain(const MainFunctionParams& p
   ui::SystemMonitor system_monitor;
   HighResolutionTimerManager hi_res_timer_manager;
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_POSIX)
   NaClMainPlatformDelegate platform(parameters);
 
   platform.PlatformInitialize();
