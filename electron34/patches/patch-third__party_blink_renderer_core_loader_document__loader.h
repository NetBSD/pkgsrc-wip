$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/loader/document_loader.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/loader/document_loader.h
@@ -325,7 +325,7 @@ class CORE_EXPORT DocumentLoader : publi
       std::optional<scheduler::TaskAttributionId>
           soft_navigation_heuristics_task_id);
 
-  void SetDefersLoading(LoaderFreezeMode);
+  void SetDefersLoading(LoaderFreezeMode) override;
 
   DocumentLoadTiming& GetTiming() { return document_load_timing_; }
 
