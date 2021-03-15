$NetBSD$

--- src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2020-07-15 18:56:02.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -185,7 +185,7 @@ InspectorMemoryAgent::GetSamplingProfile
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const WebVector<void*>& addresses) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<void*> addresses_to_symbolize;
   for (size_t i = 0; i < addresses.size(); i++) {
