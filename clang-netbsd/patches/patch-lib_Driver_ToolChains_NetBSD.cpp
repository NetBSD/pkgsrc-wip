$NetBSD$

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2017-06-19 16:00:32.334614385 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -15,6 +15,7 @@
 #include "clang/Driver/Compilation.h"
 #include "clang/Driver/Driver.h"
 #include "clang/Driver/Options.h"
+#include "clang/Driver/SanitizerArgs.h"
 #include "llvm/Option/ArgList.h"
 
 using namespace clang::driver;
@@ -246,6 +247,7 @@ void netbsd::Linker::ConstructJob(Compil
   Args.AddAllArgs(CmdArgs, options::OPT_Z_Flag);
   Args.AddAllArgs(CmdArgs, options::OPT_r);
 
+  bool NeedsSanitizerDeps = addSanitizerRuntimes(getToolChain(), Args, CmdArgs);
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs, JA);
 
   unsigned Major, Minor, Micro;
@@ -279,6 +281,8 @@ void netbsd::Linker::ConstructJob(Compil
       getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
       CmdArgs.push_back("-lm");
     }
+    if (NeedsSanitizerDeps)
+      linkSanitizerRuntimeDeps(getToolChain(), CmdArgs);
     if (Args.hasArg(options::OPT_pthread))
       CmdArgs.push_back("-lpthread");
     CmdArgs.push_back("-lc");
@@ -410,3 +414,16 @@ void NetBSD::addLibStdCxxIncludePaths(co
   addLibStdCXXIncludePaths(getDriver().SysRoot, "/usr/include/g++", "", "", "",
                            "", DriverArgs, CC1Args);
 }
+
+SanitizerMask NetBSD::getSupportedSanitizers() const {
+  const bool IsX86_64 = getTriple().getArch() == llvm::Triple::x86_64;
+  SanitizerMask Res = ToolChain::getSupportedSanitizers();
+  if (IsX86_64) {
+    Res |= SanitizerKind::Address;
+    Res |= SanitizerKind::Vptr;
+    Res |= SanitizerKind::Leak;
+    Res |= SanitizerKind::Thread;
+    Res |= SanitizerKind::SafeStack;
+  }
+  return Res;
+}
