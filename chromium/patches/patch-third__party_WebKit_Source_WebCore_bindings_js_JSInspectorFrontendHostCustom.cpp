$NetBSD: patch-third__party_WebKit_Source_WebCore_bindings_js_JSInspectorFrontendHostCustom.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp.orig	2011-04-13 08:12:33.000000000 +0000
+++ third_party/WebKit/Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp
@@ -58,8 +58,14 @@ JSValue JSInspectorFrontendHost::platfor
     DEFINE_STATIC_LOCAL(const String, platform, ("windows"));
 #elif OS(LINUX)
     DEFINE_STATIC_LOCAL(const String, platform, ("linux"));
+#elif OS(DRAGONFLY)
+    DEFINE_STATIC_LOCAL(const String, platform, ("dragonfly"));
 #elif OS(FREEBSD)
     DEFINE_STATIC_LOCAL(const String, platform, ("freebsd"));
+#elif OS(NETBSD)
+    DEFINE_STATIC_LOCAL(const String, platform, ("netbsd"));
+#elif OS(OPENBSD)
+    DEFINE_STATIC_LOCAL(const String, platform, ("openbsd"));
 #else
     DEFINE_STATIC_LOCAL(const String, platform, ("unknown"));
 #endif
