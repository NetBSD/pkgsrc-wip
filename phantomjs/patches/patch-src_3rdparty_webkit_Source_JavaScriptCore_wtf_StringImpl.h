$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_StringImpl.h,v 1.1 2013/06/18 11:02:23 fhajny Exp $

Fix for GCC 4.7.
Port over from x11/qt4-libs.
--- src/qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/text/StringImpl.h.orig	2011-12-08 05:06:02.000000000 +0000
+++ src/qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/text/StringImpl.h
@@ -24,6 +24,7 @@
 #define StringImpl_h
 
 #include <limits.h>
+#include <unistd.h>
 #include <wtf/ASCIICType.h>
 #include <wtf/CrossThreadRefCounted.h>
 #include <wtf/Forward.h>
