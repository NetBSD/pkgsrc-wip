$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/network_context.h.orig	2024-12-03 23:30:25.460256800 +0000
+++ services/network/network_context.h
@@ -696,7 +696,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:
