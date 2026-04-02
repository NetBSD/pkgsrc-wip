$NetBSD$

/tmp/wip/webkit-gtk/work/webkitgtk-2.52.1/cmake-pkgsrc-build/JavaScriptCore/PrivateHeaders/JavaScriptCore/JSCJSValue.h: In member function 'double JSC::JSValue::toIntegerOrInfinity(JSC::JSGlobalObject*) cons\
t':
/tmp/wip/webkit-gtk/work/webkitgtk-2.52.1/cmake-pkgsrc-build/JavaScriptCore/PrivateHeaders/JavaScriptCore/JSCJSValue.h:1130:12: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?
 1130 |     return isnan(d) ? 0.0 : trunc(d) + 0.0;
      |            ^~~~~
      |            std::isnan


--- Source/JavaScriptCore/runtime/JSCJSValue.h.orig	2026-04-02 09:43:05.398552050 +0000
+++ Source/JavaScriptCore/runtime/JSCJSValue.h
@@ -1127,7 +1127,7 @@ inline double JSValue::toIntegerOrInfinity(JSGlobalObj
     if (isInt32())
         return asInt32();
     double d = toNumber(globalObject);
-    return isnan(d) ? 0.0 : trunc(d) + 0.0;
+    return std::isnan(d) ? 0.0 : trunc(d) + 0.0;
 }
 
 inline bool JSValue::isUInt32() const
