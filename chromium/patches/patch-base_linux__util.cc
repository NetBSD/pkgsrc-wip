$NetBSD: patch-base_linux__util.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/linux_util.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/linux_util.cc
@@ -171,6 +171,7 @@ std::string GetLinuxDistro() {
   }
 #else
   NOTIMPLEMENTED();
+  return "Unknown";
 #endif
 }
 
