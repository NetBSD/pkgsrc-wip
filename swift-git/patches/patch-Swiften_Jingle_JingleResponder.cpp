$NetBSD: patch-Swiften_Jingle_JingleResponder.cpp,v 1.1 2014/08/18 08:25:25 thomasklausner Exp $

Make cerr a member of std.

--- Swiften/Jingle/JingleResponder.cpp.orig	2014-08-18 06:33:47.000000000 +0000
+++ Swiften/Jingle/JingleResponder.cpp
@@ -13,6 +13,8 @@
 
 #include <Swiften/Base/Log.h>
 
+#include <iostream>
+
 namespace Swift {
 
 JingleResponder::JingleResponder(JingleSessionManager* sessionManager, IQRouter* router) : SetResponder<JinglePayload>(router), sessionManager(sessionManager), router(router) {
