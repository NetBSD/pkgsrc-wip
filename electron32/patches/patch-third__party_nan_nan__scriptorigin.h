$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/nan_scriptorigin.h.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/nan_scriptorigin.h
@@ -11,7 +11,25 @@
 
 class ScriptOrigin : public v8::ScriptOrigin {
  public:
-#if defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION > 9 ||                      \
+#if defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION > 12 ||                     \
+  (V8_MAJOR_VERSION == 12 && (defined(V8_MINOR_VERSION) && (V8_MINOR_VERSION > 6\
+      || (V8_MINOR_VERSION == 7 && defined(V8_BUILD_NUMBER)                    \
+          && V8_BUILD_NUMBER >= 1)))))
+  explicit ScriptOrigin(v8::Local<v8::Value> name) :
+      v8::ScriptOrigin(name) {}
+
+  ScriptOrigin(v8::Local<v8::Value> name
+             , v8::Local<v8::Integer> line) :
+      v8::ScriptOrigin(name
+                   , To<int32_t>(line).FromMaybe(0)) {}
+
+  ScriptOrigin(v8::Local<v8::Value> name
+             , v8::Local<v8::Integer> line
+             , v8::Local<v8::Integer> column) :
+      v8::ScriptOrigin(name
+                   , To<int32_t>(line).FromMaybe(0)
+                   , To<int32_t>(column).FromMaybe(0)) {}
+#elif defined(V8_MAJOR_VERSION) && (V8_MAJOR_VERSION > 9 ||                      \
   (V8_MAJOR_VERSION == 9 && (defined(V8_MINOR_VERSION) && (V8_MINOR_VERSION > 0\
       || (V8_MINOR_VERSION == 0 && defined(V8_BUILD_NUMBER)                    \
           && V8_BUILD_NUMBER >= 1)))))
