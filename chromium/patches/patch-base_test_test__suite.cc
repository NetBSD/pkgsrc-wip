$NetBSD$

--- base/test/test_suite.cc.orig	2020-07-08 21:40:31.000000000 +0000
+++ base/test/test_suite.cc
@@ -70,7 +70,7 @@
 #include "base/test/test_support_ios.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/test/fontconfig_util_linux.h"
 #endif
 
@@ -386,7 +386,7 @@ void TestSuite::PreInitialize() {
   testing::GTEST_FLAG(catch_exceptions) = false;
 #endif
   EnableTerminationOnHeapCorruption();
-#if defined(OS_LINUX) && defined(USE_AURA)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_AURA)
   // When calling native char conversion functions (e.g wrctomb) we need to
   // have the locale set. In the absence of such a call the "C" locale is the
   // default. In the gtk code (below) gtk_init() implicitly sets a locale.
@@ -634,7 +634,7 @@ void TestSuite::Initialize() {
   // TODO(jshin): Should we set the locale via an OS X locale API here?
   i18n::SetICUDefaultLocale("en_US");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SetUpFontconfig();
 #endif
 
