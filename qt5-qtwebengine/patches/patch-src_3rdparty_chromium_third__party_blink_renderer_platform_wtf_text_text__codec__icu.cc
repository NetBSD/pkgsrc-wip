$NetBSD$

icu >= 68

--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/text/text_codec_icu.cc
@@ -326,7 +326,7 @@ void TextCodecICU::CreateICUConverter() 
   DLOG_IF(ERROR, err == U_AMBIGUOUS_ALIAS_WARNING)
       << "ICU ambiguous alias warning for encoding: " << encoding_.GetName();
   if (converter_icu_)
-    ucnv_setFallback(converter_icu_, TRUE);
+    ucnv_setFallback(converter_icu_, true);
 }
 
 int TextCodecICU::DecodeToBuffer(UChar* target,
