$NetBSD: patch-Swiften_Serializer_PayloadSerializers_JingleContentPayloadSerializer.cpp,v 1.1 2014/08/18 08:25:25 thomasklausner Exp $

Make cerr a member of std.

--- Swiften/Serializer/PayloadSerializers/JingleContentPayloadSerializer.cpp.orig	2014-08-18 06:33:47.000000000 +0000
+++ Swiften/Serializer/PayloadSerializers/JingleContentPayloadSerializer.cpp
@@ -20,6 +20,8 @@
 #include <Swiften/Serializer/PayloadSerializers/JingleIBBTransportPayloadSerializer.h>
 #include <Swiften/Serializer/PayloadSerializers/JingleS5BTransportPayloadSerializer.h>
 
+#include <iostream>
+
 namespace Swift {
 
 JingleContentPayloadSerializer::JingleContentPayloadSerializer() {
