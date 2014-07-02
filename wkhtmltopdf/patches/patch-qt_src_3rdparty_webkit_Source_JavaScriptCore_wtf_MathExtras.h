$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_MathExtras.h,v 1.1 2014/07/02 21:20:08 fhajny Exp $

Port over from x11/qt4-libs.
--- qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/MathExtras.h.orig	2014-06-07 00:54:23.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/MathExtras.h
@@ -252,7 +252,7 @@ inline int clampToInteger(unsigned value
     return static_cast<int>(std::min(value, static_cast<unsigned>(std::numeric_limits<int>::max())));
 }
 
-#if !COMPILER(MSVC) && !(COMPILER(RVCT) && PLATFORM(BREWMP)) && !OS(SOLARIS) && !OS(SYMBIAN)
+#if !COMPILER(MSVC) && !(COMPILER(RVCT) && PLATFORM(BREWMP)) && !(OS(SOLARIS) && COMPILER(GCC) && (GCC_VERSION < 40600)) && !OS(SYMBIAN)
 using std::isfinite;
 using std::isinf;
 using std::isnan;
