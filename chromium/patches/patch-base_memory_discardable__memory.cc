$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/discardable_memory.cc.orig	2024-11-14 01:04:01.814536000 +0000
+++ base/memory/discardable_memory.cc
@@ -26,7 +26,7 @@ BASE_FEATURE(kMadvFreeDiscardableMemory,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDiscardableMemoryBackingTrial,
              "DiscardableMemoryBackingTrial",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -39,7 +39,7 @@ BASE_FEATURE(kDiscardableMemoryBackingTr
 
 namespace {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 DiscardableMemoryBacking GetBackingForFieldTrial() {
   DiscardableMemoryTrialGroup trial_group =
@@ -58,7 +58,7 @@ DiscardableMemoryBacking GetBackingForFi
 
 }  // namespace
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 // Probe capabilities of this device to determine whether we should participate
 // in the discardable memory backing trial.
@@ -88,7 +88,7 @@ DiscardableMemory::DiscardableMemory() =
 DiscardableMemory::~DiscardableMemory() = default;
 
 DiscardableMemoryBacking GetDiscardableMemoryBacking() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (DiscardableMemoryBackingFieldTrialIsEnabled()) {
     return GetBackingForFieldTrial();
   }
