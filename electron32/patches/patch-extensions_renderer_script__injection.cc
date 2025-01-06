$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/renderer/script_injection.cc.orig	2024-10-18 12:34:18.116499000 +0000
+++ extensions/renderer/script_injection.cc
@@ -318,6 +318,7 @@ void ScriptInjection::InjectJs(std::set<
       blink::mojom::LoadEventBlockingOption::kBlock,
       base::BindOnce(&ScriptInjection::OnJsInjectionCompleted,
                      weak_ptr_factory_.GetWeakPtr()),
+      base::NullCallback(),
       blink::BackForwardCacheAware::kPossiblyDisallow,
       injector_->ExpectsResults(), injector_->ShouldWaitForPromise());
 }
