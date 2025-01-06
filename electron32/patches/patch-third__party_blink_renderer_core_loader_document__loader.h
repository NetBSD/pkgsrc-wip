$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/loader/document_loader.h.orig	2024-10-18 12:34:35.544119800 +0000
+++ third_party/blink/renderer/core/loader/document_loader.h
@@ -319,7 +319,7 @@ class CORE_EXPORT DocumentLoader : publi
       std::optional<scheduler::TaskAttributionId>
           soft_navigation_heuristics_task_id);
 
-  void SetDefersLoading(LoaderFreezeMode);
+  void SetDefersLoading(LoaderFreezeMode) override;
 
   DocumentLoadTiming& GetTiming() { return document_load_timing_; }
 
