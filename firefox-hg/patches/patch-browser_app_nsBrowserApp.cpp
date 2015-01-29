$NetBSD: patch-browser_app_nsBrowserApp.cpp,v 1.2 2015/01/29 10:42:07 thomasklausner Exp $

--- browser/app/nsBrowserApp.cpp.orig	2014-05-06 22:55:09.000000000 +0000
+++ browser/app/nsBrowserApp.cpp
@@ -586,6 +588,7 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
   int gotCounters;
 #if defined(XP_UNIX)
   struct rusage initialRUsage;
