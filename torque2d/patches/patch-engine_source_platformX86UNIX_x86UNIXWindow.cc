$NetBSD$

--- engine/source/platformX86UNIX/x86UNIXWindow.cc.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platformX86UNIX/x86UNIXWindow.cc
@@ -675,6 +675,8 @@ void Platform::init()
    Con::setVariable( "$platformUnixType", "Linux" );
 #elif defined(__OpenBSD__)
    Con::setVariable( "$platformUnixType", "OpenBSD" );
+#elif defined(__NetBSD__)
+   Con::setVariable( "$platformUnixType", "NetBSD" );
 #else
    Con::setVariable( "$platformUnixType", "Unknown" );
 #endif
