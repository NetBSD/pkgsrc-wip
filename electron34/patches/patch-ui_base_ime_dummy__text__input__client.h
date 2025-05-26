$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/ime/dummy_text_input_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/ime/dummy_text_input_client.h
@@ -73,7 +73,7 @@ class DummyTextInputClient : public Text
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
