$NetBSD$

--- lib/Driver/ToolChains/CommonArgs.cpp.orig	2017-06-12 12:55:07.000000000 +0000
+++ lib/Driver/ToolChains/CommonArgs.cpp
@@ -505,7 +505,8 @@ void tools::linkSanitizerRuntimeDeps(con
   CmdArgs.push_back("-lm");
   // There's no libdl on FreeBSD or RTEMS.
   if (TC.getTriple().getOS() != llvm::Triple::FreeBSD &&
-      TC.getTriple().getOS() != llvm::Triple::RTEMS)
+      TC.getTriple().getOS() != llvm::Triple::RTEMS &&
+      TC.getTriple().getOS() != llvm::Triple::NetBSD)
     CmdArgs.push_back("-ldl");
 }
 
