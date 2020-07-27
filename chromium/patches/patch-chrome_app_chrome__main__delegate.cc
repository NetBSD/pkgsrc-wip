$NetBSD$

--- chrome/app/chrome_main_delegate.cc.orig	2020-06-25 09:31:20.000000000 +0000
+++ chrome/app/chrome_main_delegate.cc
@@ -145,12 +145,12 @@
 #include "v8/include/v8.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #endif
 
 #if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_ANDROID) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/policy/policy_path_parser.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -313,7 +313,7 @@ void AdjustLinuxOOMScore(const std::stri
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == service_manager::switches::kZygoteProcess ||
 #endif
@@ -352,7 +352,7 @@ bool HandleVersionSwitches(const base::C
   return false;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -416,7 +416,7 @@ void InitializeUserDataDir(base::Command
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -499,7 +499,7 @@ void RecordMainStartupMetrics(base::Time
   startup_metric_utils::RecordApplicationStartTime(now);
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // Record the startup process creation time on supported platforms.
   startup_metric_utils::RecordStartupProcessCreationTime(
       base::Process::Current().CreationTime());
@@ -704,7 +704,7 @@ bool ChromeMainDelegate::BasicStartupCom
     *exit_code = 0;
     return true;  // Got a --version switch; exit with a success error code.
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -908,7 +908,7 @@ void ChromeMainDelegate::PreSandboxStart
 
   crash_reporter::InitializeCrashKeys();
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   ChromeCrashReporterClient::Create();
 #endif
 
@@ -920,7 +920,7 @@ void ChromeMainDelegate::PreSandboxStart
 #if defined(OS_WIN)
   child_process_logging::Init();
 #endif
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
@@ -1039,7 +1039,7 @@ void ChromeMainDelegate::PreSandboxStart
         locale;
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != service_manager::switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -1122,7 +1122,7 @@ int ChromeMainDelegate::RunProcess(
 
     // This entry is not needed on Linux, where the NaCl loader
     // process is launched via nacl_helper instead.
-#if BUILDFLAG(ENABLE_NACL) && !defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_NACL) && !defined(OS_LINUX) && !defined(OS_BSD)
     {switches::kNaClLoaderProcess, NaClMain},
 #else
     {"<invalid>", nullptr},  // To avoid constant array of size 0
