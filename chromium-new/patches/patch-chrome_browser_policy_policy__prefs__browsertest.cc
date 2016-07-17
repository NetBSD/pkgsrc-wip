$NetBSD$

--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2016-06-24 01:02:13.000000000 +0000
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -174,6 +174,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
