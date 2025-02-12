$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/webrtc/helpers_unittests.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/webrtc/helpers_unittests.cc
@@ -39,7 +39,7 @@ TEST(CreateWebRtcAudioProcessingModuleTe
   EXPECT_FALSE(config.pre_amplifier.enabled);
   EXPECT_TRUE(config.echo_canceller.enabled);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_TRUE(config.gain_controller1.enabled);
   EXPECT_TRUE(config.gain_controller2.enabled);
 #elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
@@ -77,7 +77,7 @@ TEST(CreateWebRtcAudioProcessingModuleTe
   EXPECT_EQ(config.gain_controller2, kDefaultApmConfig.gain_controller2);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      InputVolumeAdjustmentEnabledWithHybridAgc) {
   ::base::test::ScopedFeatureList feature_list;
@@ -103,7 +103,7 @@ TEST(CreateWebRtcAudioProcessingModuleTe
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      OnlyOneInputVolumeControllerEnabledOnDesktopPlatforms) {
   auto config = CreateApmGetConfig(
