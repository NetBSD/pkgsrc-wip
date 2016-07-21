$NetBSD$

--- base/linux_util.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/linux_util.cc
@@ -91,7 +91,7 @@ char g_linux_distro[kDistroSize] =
 #endif
 
 std::string GetLinuxDistro() {
-#if defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_NETBSD)
   return g_linux_distro;
 #elif defined(OS_LINUX)
   LinuxDistroHelper* distro_state_singleton = LinuxDistroHelper::GetInstance();
