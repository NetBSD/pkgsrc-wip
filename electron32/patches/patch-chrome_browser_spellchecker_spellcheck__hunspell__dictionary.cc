$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/spellchecker/spellcheck_hunspell_dictionary.cc.orig	2024-10-18 12:34:02.280866400 +0000
+++ chrome/browser/spellchecker/spellcheck_hunspell_dictionary.cc
@@ -14,6 +14,7 @@
 #include "base/functional/bind.h"
 #include "base/lazy_instance.h"
 #include "base/location.h"
+#include "base/no_destructor.h"
 #include "base/notreached.h"
 #include "base/observer_list.h"
 #include "base/path_service.h"
@@ -50,6 +51,8 @@ namespace {
 base::LazyInstance<GURL>::Leaky g_download_url_for_testing =
     LAZY_INSTANCE_INITIALIZER;
 
+base::NoDestructor<GURL> g_base_download_url_override;
+
 // Close the file.
 void CloseDictionary(base::File file) {
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
@@ -266,6 +269,10 @@ void SpellcheckHunspellDictionary::SetDo
   g_download_url_for_testing.Get() = url;
 }
 
+void SpellcheckHunspellDictionary::SetBaseDownloadURL(const GURL url) {
+  *g_base_download_url_override = url;
+}
+
 GURL SpellcheckHunspellDictionary::GetDictionaryURL() {
   if (g_download_url_for_testing.Get() != GURL())
     return g_download_url_for_testing.Get();
@@ -273,6 +280,9 @@ GURL SpellcheckHunspellDictionary::GetDi
   std::string bdict_file = dictionary_file_.path.BaseName().MaybeAsASCII();
   DCHECK(!bdict_file.empty());
 
+  if (*g_base_download_url_override != GURL())
+    return GURL(g_base_download_url_override->spec() + base::ToLowerASCII(bdict_file));
+
   static const char kDownloadServerUrl[] =
       "https://redirector.gvt1.com/edgedl/chrome/dict/";
 
