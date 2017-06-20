$NetBSD$

--- lib/Driver/ToolChains/Gnu.cpp.orig	2017-06-17 19:09:48.000000000 +0000
+++ lib/Driver/ToolChains/Gnu.cpp
@@ -347,7 +347,8 @@ static void linkXRayRuntimeDeps(const To
   CmdArgs.push_back("-lrt");
   CmdArgs.push_back("-lm");
 
-  if (TC.getTriple().getOS() != llvm::Triple::FreeBSD)
+  if (TC.getTriple().getOS() != llvm::Triple::FreeBSD &&
+      TC.getTriple().getOS() != llvm::Triple::NetBSD)
     CmdArgs.push_back("-ldl");
 }
 
