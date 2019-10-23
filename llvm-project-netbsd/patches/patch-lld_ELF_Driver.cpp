$NetBSD$

--- lld/ELF/Driver.cpp.orig	2019-10-23 20:24:31.976090112 +0000
+++ lld/ELF/Driver.cpp
@@ -55,6 +55,7 @@
 #include "llvm/Support/LEB128.h"
 #include "llvm/Support/Path.h"
 #include "llvm/Support/TarWriter.h"
+#include "llvm/Support/TargetRegistry.h"
 #include "llvm/Support/TargetSelect.h"
 #include "llvm/Support/raw_ostream.h"
 #include <cstdlib>
@@ -74,6 +75,8 @@ LinkerDriver *driver;
 
 static void setConfigs(opt::InputArgList &args);
 static void readConfigs(opt::InputArgList &args);
+static void appendDefaultSearchPaths(void);
+static void setTargetTriple(StringRef argv0, opt::InputArgList &args);
 
 bool link(ArrayRef<const char *> args, bool canExitEarly, raw_ostream &error) {
   errorHandler().logName = args::getFilenameWithoutExe(args[0]);
@@ -129,7 +132,7 @@ static std::tuple<ELFKind, uint16_t, uin
   std::pair<ELFKind, uint16_t> ret =
       StringSwitch<std::pair<ELFKind, uint16_t>>(s)
           .Cases("aarch64elf", "aarch64linux", "aarch64_elf64_le_vec",
-                 {ELF64LEKind, EM_AARCH64})
+		 "aarch64nbsd", {ELF64LEKind, EM_AARCH64})
           .Cases("armelf", "armelf_linux_eabi", {ELF32LEKind, EM_ARM})
           .Case("elf32_x86_64", {ELF32LEKind, EM_X86_64})
           .Cases("elf32btsmip", "elf32btsmipn32", {ELF32BEKind, EM_MIPS})
@@ -296,6 +299,9 @@ static void checkOptions() {
   if (config->emachine == EM_MIPS && config->gnuHash)
     error("the .gnu.hash section is not compatible with the MIPS target");
 
+  if (config->fixCortexA53Errata835769 && config->emachine != EM_AARCH64)
+    error("--fix-cortex-a53-835769 is only supported on AArch64 targets");
+
   if (config->fixCortexA53Errata843419 && config->emachine != EM_AARCH64)
     error("--fix-cortex-a53-843419 is only supported on AArch64 targets");
 
@@ -344,6 +350,9 @@ static void checkOptions() {
 
     if (config->singleRoRx && !script->hasSectionsCommand)
       error("-execute-only and -no-rosegment cannot be used together");
+  } else if (config->targetTriple.isOSNetBSD()) {
+    // force-disable RO segment on NetBSD due to ld.elf_so limitations
+    config->singleRoRx = true;
   }
 
   if (config->zRetpolineplt && config->requireCET)
@@ -394,6 +403,20 @@ static SeparateSegmentKind getZSeparate(
   return SeparateSegmentKind::None;
 }
 
+static GnuStackKind getZGnuStack(opt::InputArgList &args) {
+  for (auto *arg : args.filtered_reverse(OPT_z)) {
+    if (StringRef("execstack") == arg->getValue())
+      return GnuStackKind::Exec;
+    if (StringRef("noexecstack") == arg->getValue())
+      return GnuStackKind::NoExec;
+    if (StringRef("nognustack") == arg->getValue())
+      return GnuStackKind::None;
+  }
+
+  // default
+  return GnuStackKind::NoExec;
+}
+
 static bool isKnownZFlag(StringRef s) {
   return s == "combreloc" || s == "copyreloc" || s == "defs" ||
          s == "execstack" || s == "global" || s == "hazardplt" ||
@@ -401,7 +424,7 @@ static bool isKnownZFlag(StringRef s) {
          s == "keep-text-section-prefix" || s == "lazy" || s == "muldefs" ||
          s == "separate-code" || s == "separate-loadable-segments" ||
          s == "nocombreloc" || s == "nocopyreloc" || s == "nodefaultlib" ||
-         s == "nodelete" || s == "nodlopen" || s == "noexecstack" ||
+         s == "nodelete" || s == "nodlopen" || s == "noexecstack" || s == "nognustack" ||
          s == "nokeep-text-section-prefix" || s == "norelro" ||
          s == "noseparate-code" || s == "notext" || s == "now" ||
          s == "origin" || s == "relro" || s == "retpolineplt" ||
@@ -417,6 +440,56 @@ static void checkZOptions(opt::InputArgL
       error("unknown -z value: " + StringRef(arg->getValue()));
 }
 
+static void appendDefaultSearchPaths() {
+  if (config->targetTriple.isOSNetBSD()) {
+    // NetBSD driver relies on the linker knowing the default search paths.
+    // Please keep this in sync with clang/lib/Driver/ToolChains/NetBSD.cpp
+    // (NetBSD::NetBSD constructor)
+    switch (config->targetTriple.getArch()) {
+    case llvm::Triple::x86:
+      config->searchPaths.push_back("=/usr/lib/i386");
+      break;
+    case llvm::Triple::arm:
+    case llvm::Triple::armeb:
+    case llvm::Triple::thumb:
+    case llvm::Triple::thumbeb:
+      switch (config->targetTriple.getEnvironment()) {
+      case llvm::Triple::EABI:
+      case llvm::Triple::GNUEABI:
+        config->searchPaths.push_back("=/usr/lib/eabi");
+        break;
+      case llvm::Triple::EABIHF:
+      case llvm::Triple::GNUEABIHF:
+        config->searchPaths.push_back("=/usr/lib/eabihf");
+        break;
+      default:
+        config->searchPaths.push_back("=/usr/lib/oabi");
+        break;
+      }
+      break;
+#if 0 // TODO
+    case llvm::Triple::mips64:
+    case llvm::Triple::mips64el:
+      if (tools::mips::hasMipsAbiArg(Args, "o32"))
+        config->searchPaths.push_back("=/usr/lib/o32");
+      else if (tools::mips::hasMipsAbiArg(Args, "64"))
+        config->searchPaths.push_back("=/usr/lib/64");
+      break;
+#endif
+    case llvm::Triple::ppc:
+      config->searchPaths.push_back("=/usr/lib/powerpc");
+      break;
+    case llvm::Triple::sparc:
+      config->searchPaths.push_back("=/usr/lib/sparc");
+      break;
+    default:
+      break;
+    }
+
+    config->searchPaths.push_back("=/usr/lib");
+  }
+}
+
 void LinkerDriver::main(ArrayRef<const char *> argsArr) {
   ELFOptTable parser;
   opt::InputArgList args = parser.parse(argsArr.slice(1));
@@ -431,6 +504,8 @@ void LinkerDriver::main(ArrayRef<const c
     return;
   }
 
+  setTargetTriple(argsArr[0], args);
+
   // Handle -v or -version.
   //
   // A note about "compatible with GNU linkers" message: this is a hack for
@@ -446,8 +521,10 @@ void LinkerDriver::main(ArrayRef<const c
   // lot of "configure" scripts out there that are generated by old version
   // of Libtool. We cannot convince every software developer to migrate to
   // the latest version and re-generate scripts. So we have this hack.
-  if (args.hasArg(OPT_v) || args.hasArg(OPT_version))
+  if (args.hasArg(OPT_v) || args.hasArg(OPT_version)) {
     message(getLLDVersion() + " (compatible with GNU linkers)");
+    message("Target: " + config->targetTriple.str());
+  }
 
   if (const char *path = getReproduceOption(args)) {
     // Note that --reproduce is a debug option so you can ignore it
@@ -465,6 +542,8 @@ void LinkerDriver::main(ArrayRef<const c
 
   readConfigs(args);
 
+  appendDefaultSearchPaths();
+
   // The behavior of -v or --version is a bit strange, but this is
   // needed for compatibility with GNU linkers.
   if (args.hasArg(OPT_v) && !args.hasArg(OPT_INPUT))
@@ -812,6 +891,34 @@ static void parseClangOption(StringRef o
   error(msg + ": " + StringRef(err).trim());
 }
 
+static void setTargetTriple(StringRef argv0, opt::InputArgList &args) {
+  std::string targetError;
+
+  // Firstly, see if user specified explicit --target
+  StringRef targetOpt = args.getLastArgValue(OPT_target);
+  if (!targetOpt.empty()) {
+    if (llvm::TargetRegistry::lookupTarget(targetOpt, targetError)) {
+      config->targetTriple = llvm::Triple(targetOpt);
+      return;
+    } else
+      error("Unsupported --target=" + targetOpt + ": " + targetError);
+  }
+
+  // Secondly, try to get it from program name prefix
+  std::string ProgName = llvm::sys::path::stem(argv0);
+  size_t lastComponent = ProgName.rfind('-');
+  if (lastComponent != std::string::npos) {
+    std::string prefix = ProgName.substr(0, lastComponent);
+    if (llvm::TargetRegistry::lookupTarget(prefix, targetError)) {
+      config->targetTriple = llvm::Triple(prefix);
+      return;
+    }
+  }
+
+  // Finally, use the default target triple
+  config->targetTriple = llvm::Triple(getDefaultTargetTriple());
+}
+
 // Initializes Config members by the command line options.
 static void readConfigs(opt::InputArgList &args) {
   errorHandler().verbose = args.hasArg(OPT_verbose);
@@ -851,7 +958,8 @@ static void readConfigs(opt::InputArgLis
   config->callGraphProfileSort = args.hasFlag(
       OPT_call_graph_profile_sort, OPT_no_call_graph_profile_sort, true);
   config->enableNewDtags =
-      args.hasFlag(OPT_enable_new_dtags, OPT_disable_new_dtags, true);
+      args.hasFlag(OPT_enable_new_dtags, OPT_disable_new_dtags,
+		   !config->targetTriple.isOSNetBSD());
   config->entry = args.getLastArgValue(OPT_entry);
   config->executeOnly =
       args.hasFlag(OPT_execute_only, OPT_no_execute_only, false);
@@ -859,6 +967,7 @@ static void readConfigs(opt::InputArgLis
       args.hasFlag(OPT_export_dynamic, OPT_no_export_dynamic, false);
   config->filterList = args::getStrings(args, OPT_filter);
   config->fini = args.getLastArgValue(OPT_fini, "_fini");
+  config->fixCortexA53Errata835769 = args.hasArg(OPT_fix_cortex_a53_843419);
   config->fixCortexA53Errata843419 = args.hasArg(OPT_fix_cortex_a53_843419);
   config->fixCortexA8 = args.hasArg(OPT_fix_cortex_a8);
   config->forceBTI = args.hasArg(OPT_force_bti);
@@ -951,6 +1060,7 @@ static void readConfigs(opt::InputArgLis
   config->zCopyreloc = getZFlag(args, "copyreloc", "nocopyreloc", true);
   config->zExecstack = getZFlag(args, "execstack", "noexecstack", false);
   config->zGlobal = hasZOption(args, "global");
+  config->zGnustack = getZGnuStack(args);
   config->zHazardplt = hasZOption(args, "hazardplt");
   config->zIfuncNoplt = hasZOption(args, "ifunc-noplt");
   config->zInitfirst = hasZOption(args, "initfirst");
@@ -1269,7 +1379,7 @@ void LinkerDriver::inferMachineType() {
 // each target.
 static uint64_t getMaxPageSize(opt::InputArgList &args) {
   uint64_t val = args::getZOptionValue(args, OPT_z, "max-page-size",
-                                       target->defaultMaxPageSize);
+                                       lld::elf::target->defaultMaxPageSize);
   if (!isPowerOf2_64(val))
     error("max-page-size: value isn't a power of 2");
   if (config->nmagic || config->omagic) {
