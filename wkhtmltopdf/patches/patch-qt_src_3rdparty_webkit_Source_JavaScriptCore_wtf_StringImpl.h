$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_StringImpl.h,v 1.1 2014/07/02 21:20:08 fhajny Exp $

Fix for GCC 4.7.
Port over from x11/qt4-libs.
--- qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/text/StringImpl.h.orig	2014-06-07 00:54:23.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/text/StringImpl.h
@@ -24,6 +24,7 @@
 #define StringImpl_h
 
 #include <limits.h>
+#include <unistd.h>
 #include <wtf/ASCIICType.h>
 #include <wtf/CrossThreadRefCounted.h>
 #include <wtf/Forward.h>
