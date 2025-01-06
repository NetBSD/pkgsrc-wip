$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/spellchecker/spellcheck_service.cc.orig	2024-10-18 12:34:02.280866400 +0000
+++ chrome/browser/spellchecker/spellcheck_service.cc
@@ -21,8 +21,10 @@
 #include "base/values.h"
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
+#if 0
 #include "chrome/browser/profiles/profile.h"
 #include "chrome/browser/profiles/profiles_state.h"
+#endif
 #include "chrome/browser/spellchecker/spellcheck_factory.h"
 #include "chrome/browser/spellchecker/spellcheck_hunspell_dictionary.h"
 #include "components/language/core/browser/pref_names.h"
@@ -67,7 +69,10 @@ SpellcheckService::SpellCheckerBinder& G
 // Only record spelling-configuration metrics for profiles in which the user
 // can configure spelling.
 bool RecordSpellingConfigurationMetrics(content::BrowserContext* context) {
+#if 0
   return profiles::IsRegularUserProfile(Profile::FromBrowserContext(context));
+#endif
+  return true;
 }
 
 }  // namespace
@@ -478,6 +483,8 @@ void SpellcheckService::LoadDictionaries
         std::make_unique<SpellcheckHunspellDictionary>(
             dictionary, platform_spellcheck_language, context_, this));
     hunspell_dictionaries_.back()->AddObserver(this);
+    if (hunspell_observer_)
+      hunspell_dictionaries_.back()->AddObserver(hunspell_observer_);
     hunspell_dictionaries_.back()->Load();
   }
 
@@ -532,6 +539,20 @@ bool SpellcheckService::IsSpellcheckEnab
          (!hunspell_dictionaries_.empty() || enable_if_uninitialized);
 }
 
+void SpellcheckService::SetHunspellObserver(SpellcheckHunspellDictionary::Observer* observer) {
+  if (hunspell_observer_) {
+    for (auto& dict : hunspell_dictionaries_) {
+      dict->RemoveObserver(hunspell_observer_);
+    }
+  }
+  if (observer) {
+    for (auto& dict : hunspell_dictionaries_) {
+      dict->AddObserver(observer);
+    }
+  }
+  hunspell_observer_ = observer;
+}
+
 void SpellcheckService::OnRenderProcessHostCreated(
     content::RenderProcessHost* host) {
   InitForRenderer(host);
