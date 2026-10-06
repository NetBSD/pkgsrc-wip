$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/renderer_sandboxed_process_launcher_delegate.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/renderer_sandboxed_process_launcher_delegate.cc
@@ -35,6 +35,9 @@ namespace content {
 
 #if BUILDFLAG(USE_ZYGOTE)
 ZygoteCommunication* RendererSandboxedProcessLauncherDelegate::GetZygote() {
+  if (!use_zygote_) {
+    return nullptr;
+  }
   const base::CommandLine& browser_command_line =
       *base::CommandLine::ForCurrentProcess();
   base::CommandLine::StringType renderer_prefix =
@@ -70,6 +73,9 @@ RendererSandboxedProcessLauncherDelegate
       is_pdf_renderer_(is_pdf_renderer) {
   // PDF renderers must be jitless.
   CHECK(!is_pdf_renderer || is_jit_disabled);
+#if BUILDFLAG(USE_ZYGOTE)
+  use_zygote_ = !cmd_line->HasSwitch(switches::kNoZygote);
+#endif
   if (is_jit_disabled) {
     dynamic_code_can_be_disabled_ = true;
     return;
