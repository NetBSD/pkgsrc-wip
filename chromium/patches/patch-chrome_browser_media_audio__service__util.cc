$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/audio_service_util.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/media/audio_service_util.cc
@@ -20,7 +20,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::Value* GetPolicy(const char* policy_name) {
   const policy::PolicyMap& policies =
       g_browser_process->browser_policy_connector()
@@ -39,7 +39,7 @@ bool GetPolicyOrFeature(const char* poli
 }  // namespace
 
 bool IsAudioServiceSandboxEnabled() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetPolicyOrFeature(policy::key::kAudioSandboxEnabled,
                             features::kAudioServiceSandbox);
 #else
