$NetBSD: patch-Source_WebCore_bindings_js_JSInspectorFrontendHostCustom.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Add NetBSD support

--- src/qt/qtwebkit/Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebCore/bindings/js/JSInspectorFrontendHostCustom.cpp
@@ -63,6 +63,8 @@ JSValue JSInspectorFrontendHost::platfor
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("freebsd")));
 #elif OS(OPENBSD)
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("openbsd")));
+#elif OS(NETBSD)
+    DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("netbsd")));
 #elif OS(SOLARIS)
     DEFINE_STATIC_LOCAL(const String, platform, (ASCIILiteral("solaris")));
 #else
