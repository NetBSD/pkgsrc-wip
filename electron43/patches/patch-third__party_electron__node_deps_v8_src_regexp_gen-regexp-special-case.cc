$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/regexp/gen-regexp-special-case.cc.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/v8/src/regexp/gen-regexp-special-case.cc
@@ -9,6 +9,7 @@
 
 #include "src/base/strings.h"
 #include "src/regexp/special-case.h"
+#include "unicode/uchar.h"
 
 namespace v8 {
 namespace internal {
@@ -17,6 +18,19 @@ static const base::uc32 kSurrogateStart 
 static const base::uc32 kSurrogateEnd = 0xdfff;
 static const base::uc32 kNonBmpStart = 0x10000;
 
+// Removes supplementary code points from |set| and returns whether any were
+// present. Since Unicode 18, the case closure of a BMP character can contain
+// supplementary code points (U+1DF95 LATIN SMALL LIGATURE LONG S WITH
+// DESCENDER S case-folds to U+00DF LATIN SMALL LETTER SHARP S). Non-unicode
+// ignoreCase matching compares UTF-16 code units, so a supplementary code
+// point never matches a BMP character and does not take part in Canonicalize.
+bool RemoveSupplementary(icu::UnicodeSet& set) {
+  constexpr UChar32 kFirstSupplementary = static_cast<UChar32>(kNonBmpStart);
+  if (!set.containsSome(kFirstSupplementary, UCHAR_MAX_VALUE)) return false;
+  set.remove(kFirstSupplementary, UCHAR_MAX_VALUE);
+  return true;
+}
+
 // The following code generates "src/regexp/special-case.cc".
 void PrintSet(std::ofstream& out, const char* name,
               const icu::UnicodeSet& set) {
@@ -51,6 +65,7 @@ void PrintSpecial(std::ofstream& out) {
   icu::UnicodeSet current;
   icu::UnicodeSet special_add;
   icu::UnicodeSet ignore;
+  icu::UnicodeSet supplementary_equivalents;
   UErrorCode status = U_ZERO_ERROR;
   icu::UnicodeSet upper("[\\p{Lu}]", status);
   CHECK(U_SUCCESS(status));
@@ -63,6 +78,7 @@ void PrintSpecial(std::ofstream& out) {
     }
     current.set(i, i);
     current.closeOver(USET_CASE_INSENSITIVE);
+    if (RemoveSupplementary(current)) supplementary_equivalents.add(i);
 
     // Check to see if all characters in the case-folding equivalence
     // class as defined by UnicodeSet::closeOver all map to the same
@@ -112,6 +128,7 @@ void PrintSpecial(std::ofstream& out) {
       UChar32 canonical = RegExpCaseFolding::Canonicalize(c);
       current.set(c, c);
       current.closeOver(USET_CASE_INSENSITIVE);
+      RemoveSupplementary(current);
       current.removeAll(ignore);
       for (int32_t j = 0; j < current.getRangeCount(); j++) {
         for (UChar32 c2 = current.getRangeStart(j);
@@ -124,6 +141,7 @@ void PrintSpecial(std::ofstream& out) {
 
   PrintSet(out, "IgnoreSet", ignore);
   PrintSet(out, "SpecialAddSet", special_add);
+  PrintSet(out, "SupplementaryEquivalentsSet", supplementary_equivalents);
 }
 
 void WriteHeader(const char* header_filename) {
