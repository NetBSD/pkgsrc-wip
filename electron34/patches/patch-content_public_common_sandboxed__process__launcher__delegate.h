$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/common/sandboxed_process_launcher_delegate.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/common/sandboxed_process_launcher_delegate.h
@@ -8,6 +8,7 @@
 #include <optional>
 
 #include "base/environment.h"
+#include "base/files/file_path.h"
 #include "base/files/scoped_file.h"
 #include "base/process/process.h"
 #include "build/build_config.h"
@@ -62,10 +63,19 @@ class CONTENT_EXPORT SandboxedProcessLau
   virtual ZygoteCommunication* GetZygote();
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
-#if BUILDFLAG(IS_POSIX)
   // Override this if the process needs a non-empty environment map.
   virtual base::EnvironmentMap GetEnvironment();
-#endif  // BUILDFLAG(IS_POSIX)
+
+  // Override this if the process should not inherit parent environment.
+  virtual bool ShouldInheritEnvironment();
+
+  // Specifies the directory to change to before executing the process.
+  virtual base::FilePath GetCurrentDirectory();
+
+#if BUILDFLAG(IS_WIN)
+  // Override this if the process should not trigger mouse cursor feedback.
+  virtual bool ShouldShowFeedbackCursor();
+#endif  // #if BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_MAC)
   // Whether or not to disclaim TCC responsibility for the process, defaults to
