$NetBSD$

--- components/policy/core/common/cloud/cloud_policy_util.cc.orig	2020-07-15 18:55:55.000000000 +0000
+++ components/policy/core/common/cloud/cloud_policy_util.cc
@@ -16,7 +16,7 @@
 #include <wincred.h>
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) || defined(OS_MACOSX)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -31,7 +31,7 @@
 #import <SystemConfiguration/SCDynamicStoreCopySpecific.h>
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
@@ -62,7 +62,7 @@
 #include "base/system/sys_info.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/system/sys_info.h"
 #endif
 
@@ -76,6 +76,12 @@ std::string GetMachineName() {
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return std::string();
+#elif defined(OS_NETBSD)
+  int len = sysconf(_SC_HOST_NAME_MAX);
+  char hostname[len];
+  if (gethostname(hostname, _SC_HOST_NAME_MAX) == 0)  // Success.
+    return hostname;
+  return std::string();
 #elif defined(OS_MACOSX)
 // TODO(crbug.com/1024115): Find a different replacement for -[NSHost
 // currentHost] on iOS.
@@ -125,7 +131,7 @@ std::string GetMachineName() {
 }
 
 std::string GetOSVersion() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif defined(OS_WIN)
   base::win::OSInfo::VersionNumber version_number =
@@ -148,7 +154,7 @@ std::string GetOSArchitecture() {
 }
 
 std::string GetOSUsername() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) || defined(OS_MACOSX)
   struct passwd* creds = getpwuid(getuid());
   if (!creds || !creds->pw_name)
     return std::string();
