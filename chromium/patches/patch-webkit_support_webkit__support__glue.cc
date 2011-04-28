$NetBSD: patch-webkit_support_webkit__support__glue.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/support/webkit_support_glue.cc.orig	2011-04-13 08:01:08.000000000 +0000
+++ webkit/support/webkit_support_glue.cc
@@ -99,7 +99,7 @@ void EnableSpdy(bool enable) {
 void UserMetricsRecordAction(const std::string& action) {
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int MatchFontWithFallback(const std::string& face, bool bold,
                           bool italic, int charset) {
   return -1;
