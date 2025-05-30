$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/host/zwp_text_input_wrapper_v1.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/ozone/platform/wayland/host/zwp_text_input_wrapper_v1.cc
@@ -256,6 +256,10 @@ void ZWPTextInputWrapperV1::SetSurroundi
   // so if it exceeds 16 bits, it may be broken.
   static constexpr size_t kSizeLimit = 60000;
   if (HasAdvancedSurroundingTextSupport() && text.length() > kSizeLimit) {
+#if defined(__FreeBSD_version) && __FreeBSD_version < 1300048
+    PLOG(ERROR) << "memfd is not supported";
+    return;
+#else
     base::ScopedFD memfd(memfd_create("surrounding_text", MFD_CLOEXEC));
     if (!memfd.get()) {
       PLOG(ERROR) << "Failed to create memfd";
@@ -268,6 +272,7 @@ void ZWPTextInputWrapperV1::SetSurroundi
     zcr_extended_text_input_v1_set_large_surrounding_text(
         extended_obj_.get(), memfd.get(), text.length(),
         selection_range.start(), selection_range.end());
+#endif
   } else {
     zwp_text_input_v1_set_surrounding_text(obj_.get(), text.c_str(),
                                            selection_range.start(),
