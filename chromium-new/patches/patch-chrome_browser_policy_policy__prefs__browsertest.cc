$NetBSD$

--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2017-02-02 02:02:49.000000000 +0000
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -175,6 +175,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
