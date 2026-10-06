$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- url/url_util.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ url/url_util.h
@@ -115,6 +115,15 @@ COMPONENT_EXPORT(URL) const std::vector<
 COMPONENT_EXPORT(URL) void AddEmptyDocumentScheme(const char* new_scheme);
 COMPONENT_EXPORT(URL) const std::vector<std::string>& GetEmptyDocumentSchemes();
 
+// Adds an application-defined scheme to the list of schemes that have V8 code
+// cache enabled for the js and wasm scripts.
+// The WebUI schemes (chrome/chrome-untrusted) do not belong to this list, as
+// they are treated as a separate cache type for security purpose.
+// The http(s) schemes do not belong to this list neither, they always have V8
+// code cache enabled.
+COMPONENT_EXPORT(URL) void AddCodeCacheScheme(const char* new_scheme);
+COMPONENT_EXPORT(URL) const std::vector<std::string>& GetCodeCacheSchemes();
+
 // Adds a scheme with a predefined default handler.
 //
 // This pair of strings must be normalized protocol handler parameters as
