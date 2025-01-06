$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- url/url_util.cc.orig	2024-10-18 12:35:12.920192200 +0000
+++ url/url_util.cc
@@ -135,6 +135,9 @@ struct SchemeRegistry {
       kMaterializedViewScheme,
   };
 
+  // Embedder schemes that have V8 code cache enabled in js and wasm scripts.
+  std::vector<std::string> code_cache_schemes = {};
+
   // Schemes with a predefined default custom handler.
   std::vector<SchemeWithHandler> predefined_handler_schemes;
 
@@ -716,6 +719,15 @@ const std::vector<std::string>& GetEmpty
   return GetSchemeRegistry().empty_document_schemes;
 }
 
+void AddCodeCacheScheme(const char* new_scheme) {
+  DoAddScheme(new_scheme,
+              &GetSchemeRegistryWithoutLocking()->code_cache_schemes);
+}
+
+const std::vector<std::string>& GetCodeCacheSchemes() {
+  return GetSchemeRegistry().code_cache_schemes;
+}
+
 void AddPredefinedHandlerScheme(const char* new_scheme, const char* handler) {
   DoAddSchemeWithHandler(
       new_scheme, handler,
