$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/nan/test/cpp/news.cpp.orig	2023-09-12 12:23:33.000000000 +0000
+++ third_party/nan/test/cpp/news.cpp
@@ -115,7 +115,7 @@ NAN_METHOD(NewScript) {
 
 NAN_METHOD(NewScript2) {
   v8::ScriptOrigin origin(
-#if NODE_MODULE_VERSION >= NODE_18_0_MODULE_VERSION
+#if NODE_MODULE_VERSION >= NODE_17_0_MODULE_VERSION && NODE_MODULE_VERSION < NODE_20_0_MODULE_VERSION
     info.GetIsolate(),
 #endif
     New<v8::String>("x").ToLocalChecked());
@@ -136,7 +136,7 @@ NAN_METHOD(CompileScript) {
 
 NAN_METHOD(CompileScript2) {
   v8::ScriptOrigin origin(
-#if NODE_MODULE_VERSION >= NODE_18_0_MODULE_VERSION
+#if NODE_MODULE_VERSION >= NODE_17_0_MODULE_VERSION && NODE_MODULE_VERSION < NODE_20_0_MODULE_VERSION
     info.GetIsolate(),
 #endif
     New<v8::String>("x").ToLocalChecked());
