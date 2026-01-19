$NetBSD$

--- Source/WebCore/page/NavigatorBase.cpp.orig	2024-08-19 06:28:39.239276400 +0000
+++ Source/WebCore/page/NavigatorBase.cpp
@@ -41,7 +41,7 @@
 #include <wtf/text/MakeString.h>
 #include <wtf/text/WTFString.h>
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
 #include "sys/utsname.h"
 #include <wtf/StdLibExtras.h>
 #endif
@@ -89,7 +89,7 @@ String NavigatorBase::appVersion() const
 
 String NavigatorBase::platform() const
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(NETBSD)
     static LazyNeverDestroyed<String> platformName;
     static std::once_flag onceKey;
     std::call_once(onceKey, [] {
