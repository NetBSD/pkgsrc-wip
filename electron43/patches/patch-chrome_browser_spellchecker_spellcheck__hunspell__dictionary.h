$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/spellchecker/spellcheck_hunspell_dictionary.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/spellchecker/spellcheck_hunspell_dictionary.h
@@ -96,6 +96,8 @@ class SpellcheckHunspellDictionary : pub
   // Tests use this method to set a custom URL for downloading dictionaries.
   static void SetDownloadURLForTesting(const GURL url);
 
+  static void SetBaseDownloadURL(const GURL url);
+
  private:
   // Dictionary download status.
   enum DownloadStatus {
