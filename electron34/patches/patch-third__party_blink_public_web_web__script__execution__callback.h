$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_script_execution_callback.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/web/web_script_execution_callback.h
@@ -14,8 +14,17 @@ class TimeTicks;
 class Value;
 }
 
+namespace v8 {
+class Value;
+template <class T>
+class Local;
+}
+
 namespace blink {
 
+template <typename T>
+class WebVector;
+
 // Non-nullopt `base::Value` is passed to the callback if
 // -`WantResultOption::kWantResult` or
 //  `WantResultOption::kWantResultDateAndRegexpAllowed` is used,
@@ -43,6 +52,9 @@ namespace blink {
 using WebScriptExecutionCallback =
     base::OnceCallback<void(std::optional<base::Value>, base::TimeTicks)>;
 
+using WebScriptExecutionCallbackUnmodified =
+    base::OnceCallback<void(const WebVector<v8::Local<v8::Value>>&)>;
+
 }  // namespace blink
 
 #endif  // THIRD_PARTY_BLINK_PUBLIC_WEB_WEB_SCRIPT_EXECUTION_CALLBACK_H_
