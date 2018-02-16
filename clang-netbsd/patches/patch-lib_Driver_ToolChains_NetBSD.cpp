$NetBSD$

--- lib/Driver/ToolChains/NetBSD.cpp.orig	2018-02-16 03:40:05.438666489 +0000
+++ lib/Driver/ToolChains/NetBSD.cpp
@@ -24,6 +24,30 @@ using namespace clang::driver::toolchain
 using namespace clang;
 using namespace llvm::opt;
 
+static bool addXRayRuntime(const ToolChain &TC, const ArgList &Args,
+                           ArgStringList &CmdArgs) {
+  if (Args.hasArg(options::OPT_shared))
+    return false;
+
+  if (Args.hasFlag(options::OPT_fxray_instrument,
+                   options::OPT_fnoxray_instrument, false)) {
+    CmdArgs.push_back("-whole-archive");
+    CmdArgs.push_back(TC.getCompilerRTArgString(Args, "xray", false));
+    CmdArgs.push_back("-no-whole-archive");
+    return true;
+  }
+
+  return false;
+}
+
+static void linkXRayRuntimeDeps(const ToolChain &TC, const ArgList &Args,
+                                ArgStringList &CmdArgs) {
+  CmdArgs.push_back("--no-as-needed");
+  CmdArgs.push_back("-pthread");
+  CmdArgs.push_back("-lrt");
+  CmdArgs.push_back("-lm");
+}
+
 void netbsd::Assembler::ConstructJob(Compilation &C, const JobAction &JA,
                                      const InputInfo &Output,
                                      const InputInfoList &Inputs,
@@ -112,7 +136,9 @@ void netbsd::Linker::ConstructJob(Compil
                                   const InputInfoList &Inputs,
                                   const ArgList &Args,
                                   const char *LinkingOutput) const {
-  const Driver &D = getToolChain().getDriver();
+  const toolchains::NetBSD &ToolChain =
+    static_cast<const toolchains::NetBSD &>(getToolChain());
+  const Driver &D = ToolChain.getDriver();
   ArgStringList CmdArgs;
 
   if (!D.SysRoot.empty())
@@ -135,7 +161,7 @@ void netbsd::Linker::ConstructJob(Compil
 
   // Many NetBSD architectures support more than one ABI.
   // Determine the correct emulation for ld.
-  switch (getToolChain().getArch()) {
+  switch (ToolChain.getArch()) {
   case llvm::Triple::x86:
     CmdArgs.push_back("-m");
     CmdArgs.push_back("elf_i386");
@@ -143,7 +169,7 @@ void netbsd::Linker::ConstructJob(Compil
   case llvm::Triple::arm:
   case llvm::Triple::thumb:
     CmdArgs.push_back("-m");
-    switch (getToolChain().getTriple().getEnvironment()) {
+    switch (ToolChain.getTriple().getEnvironment()) {
     case llvm::Triple::EABI:
     case llvm::Triple::GNUEABI:
       CmdArgs.push_back("armelf_nbsd_eabi");
@@ -159,9 +185,9 @@ void netbsd::Linker::ConstructJob(Compil
     break;
   case llvm::Triple::armeb:
   case llvm::Triple::thumbeb:
-    arm::appendEBLinkFlags(Args, CmdArgs, getToolChain().getEffectiveTriple());
+    arm::appendEBLinkFlags(Args, CmdArgs, ToolChain.getEffectiveTriple());
     CmdArgs.push_back("-m");
-    switch (getToolChain().getTriple().getEnvironment()) {
+    switch (ToolChain.getTriple().getEnvironment()) {
     case llvm::Triple::EABI:
     case llvm::Triple::GNUEABI:
       CmdArgs.push_back("armelfb_nbsd_eabi");
@@ -179,13 +205,13 @@ void netbsd::Linker::ConstructJob(Compil
   case llvm::Triple::mips64el:
     if (mips::hasMipsAbiArg(Args, "32")) {
       CmdArgs.push_back("-m");
-      if (getToolChain().getArch() == llvm::Triple::mips64)
+      if (ToolChain.getArch() == llvm::Triple::mips64)
         CmdArgs.push_back("elf32btsmip");
       else
         CmdArgs.push_back("elf32ltsmip");
     } else if (mips::hasMipsAbiArg(Args, "64")) {
       CmdArgs.push_back("-m");
-      if (getToolChain().getArch() == llvm::Triple::mips64)
+      if (ToolChain.getArch() == llvm::Triple::mips64)
         CmdArgs.push_back("elf64btsmip");
       else
         CmdArgs.push_back("elf64ltsmip");
@@ -226,16 +252,16 @@ void netbsd::Linker::ConstructJob(Compil
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
     if (!Args.hasArg(options::OPT_shared)) {
       CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("crt0.o")));
+          Args.MakeArgString(ToolChain.GetFilePath("crt0.o")));
     }
     CmdArgs.push_back(
-        Args.MakeArgString(getToolChain().GetFilePath("crti.o")));
+        Args.MakeArgString(ToolChain.GetFilePath("crti.o")));
     if (Args.hasArg(options::OPT_shared) || Args.hasArg(options::OPT_pie)) {
       CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("crtbeginS.o")));
+          Args.MakeArgString(ToolChain.GetFilePath("crtbeginS.o")));
     } else {
       CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("crtbegin.o")));
+          Args.MakeArgString(ToolChain.GetFilePath("crtbegin.o")));
     }
   }
 
@@ -248,13 +274,14 @@ void netbsd::Linker::ConstructJob(Compil
   Args.AddAllArgs(CmdArgs, options::OPT_r);
 
   bool NeedsSanitizerDeps = addSanitizerRuntimes(getToolChain(), Args, CmdArgs);
+  bool NeedsXRayDeps = addXRayRuntime(ToolChain, Args, CmdArgs);
   AddLinkerInputs(getToolChain(), Inputs, Args, CmdArgs, JA);
 
   unsigned Major, Minor, Micro;
-  getToolChain().getTriple().getOSVersion(Major, Minor, Micro);
+  ToolChain.getTriple().getOSVersion(Major, Minor, Micro);
   bool useLibgcc = true;
   if (Major >= 7 || Major == 0) {
-    switch (getToolChain().getArch()) {
+    switch (ToolChain.getArch()) {
     case llvm::Triple::aarch64:
     case llvm::Triple::aarch64_be:
     case llvm::Triple::arm:
@@ -278,12 +305,14 @@ void netbsd::Linker::ConstructJob(Compil
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nodefaultlibs)) {
     addOpenMPRuntime(CmdArgs, getToolChain(), Args);
     if (D.CCCIsCXX()) {
-      if (getToolChain().ShouldLinkCXXStdlib(Args))
-        getToolChain().AddCXXStdlibLibArgs(Args, CmdArgs);
+      if (ToolChain.ShouldLinkCXXStdlib(Args))
+        ToolChain.AddCXXStdlibLibArgs(Args, CmdArgs);
       CmdArgs.push_back("-lm");
     }
     if (NeedsSanitizerDeps)
       linkSanitizerRuntimeDeps(getToolChain(), CmdArgs);
+    if (NeedsXRayDeps)
+      linkXRayRuntimeDeps(ToolChain, Args, CmdArgs);
     if (Args.hasArg(options::OPT_pthread))
       CmdArgs.push_back("-lpthread");
     CmdArgs.push_back("-lc");
@@ -308,16 +337,16 @@ void netbsd::Linker::ConstructJob(Compil
   if (!Args.hasArg(options::OPT_nostdlib, options::OPT_nostartfiles)) {
     if (Args.hasArg(options::OPT_shared) || Args.hasArg(options::OPT_pie))
       CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("crtendS.o")));
+          Args.MakeArgString(ToolChain.GetFilePath("crtendS.o")));
     else
       CmdArgs.push_back(
-          Args.MakeArgString(getToolChain().GetFilePath("crtend.o")));
-    CmdArgs.push_back(Args.MakeArgString(getToolChain().GetFilePath("crtn.o")));
+          Args.MakeArgString(ToolChain.GetFilePath("crtend.o")));
+    CmdArgs.push_back(Args.MakeArgString(ToolChain.GetFilePath("crtn.o")));
   }
 
-  getToolChain().addProfileRTLibs(Args, CmdArgs);
+  ToolChain.addProfileRTLibs(Args, CmdArgs);
 
-  const char *Exec = Args.MakeArgString(getToolChain().GetLinkerPath());
+  const char *Exec = Args.MakeArgString(ToolChain.GetLinkerPath());
   C.addCommand(llvm::make_unique<Command>(JA, *this, Exec, CmdArgs, Inputs));
 }
 
