$NetBSD: patch-content_utility_utility__thread__impl.cc,v 1.1 2025/02/06 09:58:08 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/utility_thread_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/utility/utility_thread_impl.cc
@@ -31,7 +31,7 @@
 #include "mojo/public/cpp/bindings/pending_receiver.h"
 #include "mojo/public/cpp/bindings/service_factory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -251,7 +251,8 @@ void UtilityThreadImpl::Init() {
 
   GetContentClient()->utility()->UtilityThreadStarted();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   SandboxedProcessThreadTypeHandler::NotifyMainChildThreadCreated();
 #endif
 
