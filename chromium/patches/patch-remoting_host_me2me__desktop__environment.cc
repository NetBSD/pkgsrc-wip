$NetBSD$

--- remoting/host/me2me_desktop_environment.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ remoting/host/me2me_desktop_environment.cc
@@ -129,7 +129,7 @@ bool Me2MeDesktopEnvironment::Initialize
 
   // Otherwise, if the session is shared with the local user start monitoring
   // the local input and create the in-session UI.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool want_user_interface = false;
 #elif defined(OS_MACOSX)
   // Don't try to display any UI on top of the system's login screen as this
