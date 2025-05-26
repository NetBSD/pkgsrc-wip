$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/spellchecker/spellcheck_service.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/spellchecker/spellcheck_service.h
@@ -135,6 +135,8 @@ class SpellcheckService : public KeyedSe
   // dictionaries available.
   bool IsSpellcheckEnabled() const;
 
+  void SetHunspellObserver(SpellcheckHunspellDictionary::Observer* observer);
+
   // content::RenderProcessHostCreationObserver implementation.
   void OnRenderProcessHostCreated(content::RenderProcessHost* host) override;
 
@@ -299,6 +301,8 @@ class SpellcheckService : public KeyedSe
   // A pointer to the BrowserContext which this service refers to.
   raw_ptr<content::BrowserContext> context_;
 
+  raw_ptr<SpellcheckHunspellDictionary::Observer> hunspell_observer_ = nullptr;
+
   std::unique_ptr<SpellCheckHostMetrics> metrics_;
 
   std::unique_ptr<SpellcheckCustomDictionary> custom_dictionary_;
