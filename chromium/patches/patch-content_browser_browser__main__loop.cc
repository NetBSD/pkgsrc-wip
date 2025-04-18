$NetBSD: patch-content_browser_browser__main__loop.cc,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_main_loop.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/browser_main_loop.cc
@@ -250,6 +250,12 @@
 #include "mojo/public/cpp/bindings/lib/test_random_mojo_delays.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/public/common/zygote/sandbox_support_linux.h"
+#include "sandbox/policy/sandbox.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -545,6 +551,12 @@ int BrowserMainLoop::EarlyInitialization
   // by now since a thread to start the ServiceManager has been created
   // before the browser main loop starts.
   DCHECK(SandboxHostLinux::GetInstance()->IsInitialized());
+#elif BUILDFLAG(IS_BSD)
+  base::FileHandleMappingVector additional_remapped_fds;
+  base::LaunchOptions options;
+  SandboxHostLinux::GetInstance()->Init();
+  const int sfd = SandboxHostLinux::GetInstance()->GetChildSocket();
+  options.fds_to_remap.push_back(std::make_pair(sfd, GetSandboxFD()));
 #endif
 
   // GLib's spawning of new processes is buggy, so it's important that at this
@@ -583,7 +595,7 @@ int BrowserMainLoop::EarlyInitialization
       base::ThreadType::kDisplayCritical);
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache, and the default limit on Apple is low (256), so bump it up.
 
