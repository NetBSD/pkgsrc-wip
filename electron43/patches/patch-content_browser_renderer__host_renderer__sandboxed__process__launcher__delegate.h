$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/renderer_sandboxed_process_launcher_delegate.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/renderer_sandboxed_process_launcher_delegate.h
@@ -18,6 +18,11 @@ class CONTENT_EXPORT RendererSandboxedPr
  public:
   RendererSandboxedProcessLauncherDelegate() = default;
 
+#if BUILDFLAG(USE_ZYGOTE)
+  RendererSandboxedProcessLauncherDelegate(bool use_zygote):
+    use_zygote_(use_zygote) {}
+#endif
+
   ~RendererSandboxedProcessLauncherDelegate() override = default;
 
 #if BUILDFLAG(USE_ZYGOTE)
@@ -30,6 +35,11 @@ class CONTENT_EXPORT RendererSandboxedPr
 
   // sandbox::policy::SandboxDelegate:
   sandbox::mojom::Sandbox GetSandboxType() override;
+
+ private:
+#if BUILDFLAG(USE_ZYGOTE)
+  bool use_zygote_ = true;
+#endif
 };
 
 #if BUILDFLAG(IS_WIN)
