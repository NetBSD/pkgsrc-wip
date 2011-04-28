$NetBSD: patch-base_i18n_number__formatting.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/i18n/number_formatting.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/i18n/number_formatting.cc
@@ -35,7 +35,7 @@ struct NumberFormatWrapper {
 
 static LazyInstance<NumberFormatWrapper> g_number_format(LINKER_INITIALIZED);
 
-string16 FormatNumber(int64 number) {
+string16 FormatNumber(int64_t number) {
   icu::NumberFormat* number_format = g_number_format.Get().number_format.get();
 
   if (!number_format) {
