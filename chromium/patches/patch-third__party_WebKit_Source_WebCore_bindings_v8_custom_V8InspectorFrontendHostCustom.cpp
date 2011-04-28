$NetBSD: patch-third__party_WebKit_Source_WebCore_bindings_v8_custom_V8InspectorFrontendHostCustom.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/bindings/v8/custom/V8InspectorFrontendHostCustom.cpp.orig	2011-04-13 08:12:33.000000000 +0000
+++ third_party/WebKit/Source/WebCore/bindings/v8/custom/V8InspectorFrontendHostCustom.cpp
@@ -47,8 +47,14 @@ v8::Handle<v8::Value> V8InspectorFronten
     return v8String("mac");
 #elif defined(OS_LINUX)
     return v8String("linux");
+#elif defined(OS_DRAGONFLY)
+    return v8String("dragonfly");
 #elif defined(OS_FREEBSD)
     return v8String("freebsd");
+#elif defined(OS_NETBSD)
+    return v8String("netbsd");
+#elif defined(OS_OPENBSD)
+    return v8String("openbsd");
 #elif defined(OS_WIN)
     return v8String("windows");
 #else
