$NetBSD: patch-ui_base_l10n_l10n__util.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- ui/base/l10n/l10n_util.cc.orig	2011-05-24 08:01:59.000000000 +0000
+++ ui/base/l10n/l10n_util.cc
@@ -320,7 +320,7 @@ bool CheckAndResolveLocale(const std::st
 // if "foo bar" is RTL. So this function prepends the necessary RLM in such
 // cases.
 void AdjustParagraphDirectionality(string16* paragraph) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (base::i18n::IsRTL() &&
       base::i18n::StringContainsStrongRTLChars(*paragraph)) {
     paragraph->insert(0, 1, static_cast<char16>(base::i18n::kRightToLeftMark));
