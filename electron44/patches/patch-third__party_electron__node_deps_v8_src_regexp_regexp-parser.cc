$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/regexp/regexp-parser.cc.orig	2026-10-20 17:54:51.000000000 +0000
+++ third_party/electron_node/deps/v8/src/regexp/regexp-parser.cc
@@ -9,6 +9,7 @@
 #include "src/regexp/regexp-ast.h"
 #include "src/regexp/regexp-macro-assembler.h"
 #include "src/regexp/regexp.h"
+#include "src/regexp/special-case.h"
 #include "src/strings/char-predicates-inl.h"
 #include "src/utils/ostreams.h"
 #include "src/utils/utils.h"
@@ -155,6 +156,10 @@ void RegExpTextBuilder::FlushText() {
 
 void RegExpTextBuilder::AddCharacter(base::uc16 c) {
   FlushPendingSurrogate();
+  if (NeedsDesugaringForIgnoreCase(c)) {
+    AddClassRangesForDesugaring(c);
+    return;
+  }
   if (characters_ == nullptr) {
     characters_ = zone()->New<ZoneList<base::uc16>>(4, zone());
   }
@@ -237,15 +242,18 @@ bool RegExpTextBuilder::NeedsDesugaringF
   return false;
 }
 
-// We only use this for characters made of surrogate pairs.  All other
-// characters outside of character classes are made case independent in the
-// code generation.
+// Desugar supplementary characters with case equivalents and BMP characters
+// with supplementary equivalents. Other atoms are folded during code
+// generation.
 bool RegExpTextBuilder::NeedsDesugaringForIgnoreCase(base::uc32 c) {
 #ifdef V8_INTL_SUPPORT
   if (IsUnicodeMode() && ignore_case()) {
+    if (c <= unibrow::Utf16::kMaxNonSurrogateCharCode) {
+      return RegExpCaseFolding::HasSupplementaryEquivalents(
+          static_cast<base::uc16>(c));
+    }
     icu::UnicodeSet set(c, c);
-    set.closeOver(USET_CASE_INSENSITIVE);
-    set.removeAllStrings();
+    RegExpCaseFolding::CloseOver(set, RegExpCaseFolding::Mode::kUnicode);
     return set.size() > 1;
   }
   // In the case where ICU is not included, we act as if the unicode flag is
