$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc.orig	2024-10-18 12:34:36.999452400 +0000
+++ third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc
@@ -615,6 +615,7 @@ static void GbkUrlEscapedEntityCallack(
                               code_point, reason, err);
 }
 
+#if !BUILDFLAG(IS_BSD)
 static void GbkCallbackSubstitute(const void* context,
                                   UConverterFromUnicodeArgs* from_unicode_args,
                                   const UChar* code_units,
@@ -632,6 +633,7 @@ static void GbkCallbackSubstitute(const 
   UCNV_FROM_U_CALLBACK_SUBSTITUTE(context, from_unicode_args, code_units,
                                   length, code_point, reason, err);
 }
+#endif
 #endif  // USING_SYSTEM_ICU
 
 static void NotReachedEntityCallback(const void* context,
