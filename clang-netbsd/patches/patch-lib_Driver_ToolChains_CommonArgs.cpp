$NetBSD$

--- lib/Driver/ToolChains/CommonArgs.cpp.orig	2017-07-16 20:46:13.000000000 +0000
+++ lib/Driver/ToolChains/CommonArgs.cpp
@@ -525,7 +525,8 @@ void tools::linkSanitizerRuntimeDeps(con
   // There's no libdl on FreeBSD or RTEMS.
   if (TC.getTriple().getOS() != llvm::Triple::FreeBSD &&
       TC.getTriple().getOS() != llvm::Triple::NetBSD &&
-      TC.getTriple().getOS() != llvm::Triple::RTEMS)
+      TC.getTriple().getOS() != llvm::Triple::RTEMS &&
+      TC.getTriple().getOS() != llvm::Triple::NetBSD)
     CmdArgs.push_back("-ldl");
 }
 
