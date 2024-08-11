$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ime/fake_text_input_client.h.orig	2024-07-24 02:45:10.260038100 +0000
+++ ui/base/ime/fake_text_input_client.h
@@ -98,7 +98,7 @@ class FakeTextInputClient : public TextI
   void SetTextEditCommandForNextKeyEvent(TextEditCommand command) override;
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
