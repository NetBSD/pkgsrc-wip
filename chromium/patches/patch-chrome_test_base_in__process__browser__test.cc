$NetBSD$

--- chrome/test/base/in_process_browser_test.cc.orig	2020-07-08 21:40:37.000000000 +0000
+++ chrome/test/base/in_process_browser_test.cc
@@ -6,6 +6,10 @@
 
 #include <utility>
 
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
+
 #include "base/auto_reset.h"
 #include "base/bind.h"
 #include "base/command_line.h"
@@ -105,7 +109,7 @@
 #include "ui/events/test/event_generator.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/views/test/test_desktop_screen_x11.h"
 #endif
 
@@ -282,7 +286,7 @@ void InProcessBrowserTest::SetUp() {
   // Cookies). Without this on Mac and Linux, many tests will hang waiting for a
   // user to approve KeyChain/kwallet access. On Windows this is not needed as
   // OS APIs never block.
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   OSCryptMocker::SetUp();
 #endif
 
@@ -344,7 +348,7 @@ void InProcessBrowserTest::TearDown() {
   com_initializer_.reset();
 #endif
   BrowserTestBase::TearDown();
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   OSCryptMocker::TearDown();
 #endif
 
