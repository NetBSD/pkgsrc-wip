$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/renderer/script_injection.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/renderer/script_injection.cc
@@ -317,6 +317,7 @@ void ScriptInjection::InjectJs(std::set<
       blink::mojom::LoadEventBlockingOption::kBlock,
       base::BindOnce(&ScriptInjection::OnJsInjectionCompleted,
                      weak_ptr_factory_.GetWeakPtr()),
+      base::NullCallback(),
       blink::BackForwardCacheAware::kPossiblyDisallow,
       injector_->ExpectsResults(), injector_->ShouldWaitForPromise());
 }
