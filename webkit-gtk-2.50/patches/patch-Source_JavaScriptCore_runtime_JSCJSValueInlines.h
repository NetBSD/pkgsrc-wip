$NetBSD$

/scratch/wip/webkit-gtk-2.46/work/webkitgtk-2.50.0/Source/JavaScriptCore/runtime/JSCJSValueInlines.h:136:12: error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?
  136 |     return isnan(d) ? 0.0 : trunc(d) + 0.0;
      |            ^~~~~
      |            std::isnan


--- Source/JavaScriptCore/runtime/JSCJSValueInlines.h.orig	2025-09-23 16:35:34.449018790 +0000
+++ Source/JavaScriptCore/runtime/JSCJSValueInlines.h
@@ -133,7 +133,7 @@ inline double JSValue::toIntegerOrInfini
     if (isInt32())
         return asInt32();
     double d = toNumber(globalObject);
-    return isnan(d) ? 0.0 : trunc(d) + 0.0;
+    return std::isnan(d) ? 0.0 : trunc(d) + 0.0;
 }
 
 inline bool JSValue::isUInt32() const
