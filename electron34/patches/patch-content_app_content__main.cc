$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/app/content_main.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/app/content_main.cc
@@ -227,7 +227,7 @@ NO_STACK_PROTECTOR int RunContentProcess
     base::EnableTerminationOnOutOfMemory();
     logging::RegisterAbslAbortHook();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The various desktop environments set this environment variable that
     // allows the dbus client library to connect directly to the bus. When this
     // variable is not set (test environments like xvfb-run), the dbus client
@@ -313,7 +313,7 @@ NO_STACK_PROTECTOR int RunContentProcess
     command_line->AppendSwitch(switches::kUseMobileUserAgent);
 #endif
 
-#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD)
+#if (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)) && !defined(COMPONENT_BUILD) && defined(notyet)
     base::subtle::EnableFDOwnershipEnforcement(true);
 #endif
 
@@ -326,16 +326,14 @@ NO_STACK_PROTECTOR int RunContentProcess
 
 #if BUILDFLAG(IS_WIN)
     base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
-    if (command_line->HasSwitch(switches::kHeadless)) {
-      // When running in headless mode we want stdio routed however if
-      // console does not exist we should not create one.
-      base::RouteStdioToConsole(/*create_console_if_not_found*/ false);
-    } else if (command_line->HasSwitch(switches::kEnableLogging)) {
-      // Route stdio to parent console (if any) or create one, do not create a
-      // console in children if handles are being passed.
-      bool create_console = command_line->GetSwitchValueASCII(
-                                switches::kEnableLogging) != "handle";
-      base::RouteStdioToConsole(create_console);
+    // Route stdio to parent console (if any) or create one.
+    bool const log_to_stderr =
+        command_line->HasSwitch(switches::kEnableLogging) &&
+        command_line->GetSwitchValueASCII(switches::kEnableLogging) != "file" &&
+        !command_line->HasSwitch(switches::kLogFile) &&
+        command_line->GetSwitchValueASCII(switches::kEnableLogging) != "handle";
+    if (log_to_stderr) {
+      base::RouteStdioToConsole(true);
     }
 #endif
 
