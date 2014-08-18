$NetBSD: patch-Swiften_Client_ClientSession.cpp,v 1.1 2014/08/18 08:25:25 thomasklausner Exp $

Make cerr a member of std.

--- Swiften/Client/ClientSession.cpp.orig	2014-08-18 06:33:47.000000000 +0000
+++ Swiften/Client/ClientSession.cpp
@@ -46,6 +46,8 @@
 #include <Swiften/TLS/ServerIdentityVerifier.h>
 #include <Swiften/Base/Log.h>
 
+#include <iostream>
+
 #ifdef SWIFTEN_PLATFORM_WIN32
 #include <Swiften/Base/WindowsRegistry.h>
 #endif
