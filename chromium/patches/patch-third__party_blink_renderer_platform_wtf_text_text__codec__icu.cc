$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc.orig	2024-07-24 02:44:47.029788000 +0000
+++ third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc
@@ -610,6 +610,7 @@ static void GbkUrlEscapedEntityCallack(
                               code_point, reason, err);
 }
 
+#if !BUILDFLAG(IS_BSD)
 static void GbkCallbackSubstitute(const void* context,
                                   UConverterFromUnicodeArgs* from_unicode_args,
                                   const UChar* code_units,
@@ -627,6 +628,7 @@ static void GbkCallbackSubstitute(const 
   UCNV_FROM_U_CALLBACK_SUBSTITUTE(context, from_unicode_args, code_units,
                                   length, code_point, reason, err);
 }
+#endif
 #endif  // USING_SYSTEM_ICU
 
 static void NotReachedEntityCallback(const void* context,
