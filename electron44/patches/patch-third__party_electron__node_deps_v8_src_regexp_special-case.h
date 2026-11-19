$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/regexp/special-case.h.orig	2026-10-20 17:54:51.000000000 +0000
+++ third_party/electron_node/deps/v8/src/regexp/special-case.h
@@ -7,8 +7,8 @@
 
 #ifdef V8_INTL_SUPPORT
 #include "src/base/logging.h"
+#include "src/base/strings.h"
 #include "src/common/globals.h"
-
 #include "unicode/uchar.h"
 #include "unicode/uniset.h"
 #include "unicode/unistr.h"
@@ -71,9 +71,17 @@ namespace internal {
 // another character. Characters that match no other characters in
 // their equivalence class are added to IgnoreSet. Characters that
 // match at least one other character are added to SpecialAddSet.
+// Supplementary code points are ignored throughout: non-unicode matching
+// compares UTF-16 code units, so they can never match a BMP character.
+//
+// The generator additionally emits SupplementaryEquivalentsSet, the BMP
+// characters whose Unicode case closure contains supplementary code points.
+// This set is used for unicode-mode matching, see HasSupplementaryEquivalents.
 
 class RegExpCaseFolding final : public AllStatic {
  public:
+  enum class Mode { kNonUnicode, kUnicode };
+
   static const icu::UnicodeSet& IgnoreSet();
   static const icu::UnicodeSet& SpecialAddSet();
 
@@ -108,6 +116,43 @@ class RegExpCaseFolding final : public A
     // h. Return cu.
     return cu;
   }
+
+  // Close a set of characters under case equivalence, preserving its
+  // original members. Non-unicode inputs must be UTF-16 code units.
+  static void CloseOver(icu::UnicodeSet& set, Mode mode) {
+    if (mode == Mode::kUnicode) {
+      set.closeOver(USET_SIMPLE_CASE_INSENSITIVE);
+      return;
+    }
+    DCHECK(!set.containsSome(0x10000, 0x10ffff));
+    if (IgnoreSet().containsNone(set)) {
+      CloseOverNonUnicode(set);
+      return;
+    }
+    if (IgnoreSet().containsAll(set)) return;
+    // Ignored characters neither contribute nor acquire equivalents, but
+    // must remain in the result if they were explicitly present.
+    icu::UnicodeSet ignored(set);
+    ignored.retainAll(IgnoreSet());
+    set.removeAll(IgnoreSet());
+    CloseOverNonUnicode(set);
+    set.addAll(ignored);
+  }
+
+  // Whether c has supplementary Unicode case equivalents.
+  static bool HasSupplementaryEquivalents(base::uc16 c) {
+    return SupplementaryEquivalentsSet().contains(c);
+  }
+
+ private:
+  static const icu::UnicodeSet& SupplementaryEquivalentsSet();
+
+  // Requires a set containing no IgnoreSet characters.
+  static void CloseOverNonUnicode(icu::UnicodeSet& set) {
+    set.closeOver(USET_SIMPLE_CASE_INSENSITIVE);
+    set.removeAll(IgnoreSet());
+    set.remove(0x10000, 0x10ffff);
+  }
 };
 
 }  // namespace internal
