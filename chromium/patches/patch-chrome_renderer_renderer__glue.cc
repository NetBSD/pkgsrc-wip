$NetBSD: patch-chrome_renderer_renderer__glue.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/renderer_glue.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/renderer_glue.cc
@@ -43,7 +43,7 @@
 
 #if defined(OS_WIN)
 #include <strsafe.h>  // note: per msdn docs, this must *follow* other includes
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/renderer/renderer_sandbox_support_linux.h"
 #endif
 
@@ -305,7 +305,7 @@ bool LaunchSelLdr(const char* alleged_ur
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int MatchFontWithFallback(const std::string& face, bool bold,
                           bool italic, int charset) {
   return renderer_sandbox_support::MatchFontWithFallback(
