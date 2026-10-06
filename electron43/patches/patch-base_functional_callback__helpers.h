$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/functional/callback_helpers.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/functional/callback_helpers.h
@@ -100,6 +100,22 @@ RepeatingCallback<void(Args...)> Forward
                        std::move(v));
 }
 
+// Wraps the given OnceCallback into a RepeatingCallback that relays its
+// invocation to the original OnceCallback on the first invocation. The
+// following invocations are just ignored.
+//
+// Note that this deliberately subverts the Once/Repeating paradigm of Callbacks
+// but helps ease the migration from old-style Callbacks. Avoid if possible; use
+// if necessary for migration. TODO(tzik): Remove it. https://crbug.com/730593
+template <typename... Args>
+RepeatingCallback<void(Args...)> AdaptCallbackForRepeating(
+    OnceCallback<void(Args...)> callback) {
+  using Helper = internal::OnceCallbackHolder<Args...>;
+  return base::BindRepeating(
+      &Helper::Run, std::make_unique<Helper>(std::move(callback),
+                                             /*ignore_extra_runs=*/true));
+}
+
 // Wraps the given OnceCallback and returns two OnceCallbacks with an identical
 // signature. On first invokation of either returned callbacks, the original
 // callback is invoked. Invoking the remaining callback results in a crash.
