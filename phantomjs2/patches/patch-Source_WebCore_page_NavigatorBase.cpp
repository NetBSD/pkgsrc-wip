$NetBSD: patch-Source_WebCore_page_NavigatorBase.cpp,v 1.1 2015/02/23 16:11:07 leot1990 Exp $

* Treat *BSD like Linux

--- src/qt/qtwebkit/Source/WebCore/page/NavigatorBase.cpp.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WebCore/page/NavigatorBase.cpp
@@ -30,7 +30,7 @@
 #include "NetworkStateNotifier.h"
 #include <wtf/text/WTFString.h>
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
 #include "sys/utsname.h"
 #include <wtf/StdLibExtras.h>
 #endif
@@ -86,7 +86,7 @@ String NavigatorBase::appVersion() const
 
 String NavigatorBase::platform() const
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
     if (!String(WEBCORE_NAVIGATOR_PLATFORM).isEmpty())
         return WEBCORE_NAVIGATOR_PLATFORM;
     struct utsname osname;
