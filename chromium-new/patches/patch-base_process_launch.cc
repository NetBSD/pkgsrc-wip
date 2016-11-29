$NetBSD$

--- base/process/launch.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/process/launch.cc
@@ -15,7 +15,7 @@ LaunchOptions::~LaunchOptions() = defaul
 
 LaunchOptions LaunchOptionsForTest() {
   LaunchOptions options;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // To prevent accidental privilege sharing to an untrusted child, processes
   // are started with PR_SET_NO_NEW_PRIVS. Do not set that here, since this
   // new child will be used for testing only.
