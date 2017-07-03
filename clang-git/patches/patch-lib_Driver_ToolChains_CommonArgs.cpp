$NetBSD$

--- lib/Driver/ToolChains/CommonArgs.cpp.orig	2017-07-02 16:11:01.135157051 +0000
+++ lib/Driver/ToolChains/CommonArgs.cpp
@@ -524,6 +524,7 @@ void tools::linkSanitizerRuntimeDeps(con
   CmdArgs.push_back("-lm");
   // There's no libdl on FreeBSD or RTEMS.
   if (TC.getTriple().getOS() != llvm::Triple::FreeBSD &&
+      TC.getTriple().getOS() != llvm::Triple::NetBSD &&
       TC.getTriple().getOS() != llvm::Triple::RTEMS)
     CmdArgs.push_back("-ldl");
 }
