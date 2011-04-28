$NetBSD: patch-webkit_tools_test__shell_test__shell.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/tools/test_shell/test_shell.cc.orig	2011-04-13 08:01:08.000000000 +0000
+++ webkit/tools/test_shell/test_shell.cc
@@ -880,7 +880,7 @@ bool LaunchSelLdr(const char* alleged_ur
   return false;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int MatchFontWithFallback(const std::string& face, bool bold,
                           bool italic, int charset) {
   return -1;
