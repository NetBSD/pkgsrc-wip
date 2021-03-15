$NetBSD$

icu >= 68

--- src/3rdparty/chromium/third_party/blink/renderer/platform/text/unicode_utilities.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/text/unicode_utilities.cc
@@ -300,7 +300,7 @@ void NormalizeCharactersIntoNFCForm(cons
   DCHECK(U_SUCCESS(status));
   int32_t input_length = static_cast<int32_t>(length);
   // copy-on-write.
-  icu::UnicodeString normalized(FALSE, characters, input_length);
+  icu::UnicodeString normalized(false, characters, input_length);
   // In the vast majority of cases, input is already NFC. Run a quick check
   // to avoid normalizing the entire input unnecessarily.
   int32_t normalized_prefix_length =
