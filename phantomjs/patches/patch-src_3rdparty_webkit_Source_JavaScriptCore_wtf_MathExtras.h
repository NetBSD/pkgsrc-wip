$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_MathExtras.h,v 1.1 2013/06/18 11:02:22 fhajny Exp $

Port over from x11/qt4-libs.
--- src/qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/MathExtras.h.orig	2011-12-08 06:06:02.000000000 +0100
+++ src/qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/MathExtras.h	2012-01-15 01:09:37.169459335 +0100
@@ -252,7 +252,7 @@ inline int clampToInteger(unsigned value
     return static_cast<int>(std::min(value, static_cast<unsigned>(std::numeric_limits<int>::max())));
 }
 
-#if !COMPILER(MSVC) && !(COMPILER(RVCT) && PLATFORM(BREWMP)) && !OS(SOLARIS) && !OS(SYMBIAN)
+#if !COMPILER(MSVC) && !(COMPILER(RVCT) && PLATFORM(BREWMP)) && !(OS(SOLARIS) && COMPILER(GCC) && (GCC_VERSION < 40600)) && !OS(SYMBIAN)
 using std::isfinite;
 using std::isinf;
 using std::isnan;
