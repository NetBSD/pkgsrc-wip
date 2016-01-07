$NetBSD$

--- plugins/DebuggerCore/DebuggerCore.pro.orig	2013-07-26 01:50:18.000000000 +0000
+++ plugins/DebuggerCore/DebuggerCore.pro
@@ -13,6 +13,11 @@ unix {
 		INCLUDEPATH += unix/linux
 	}
 
+	netbsd-* {
+		VPATH       += unix/netbsd
+		INCLUDEPATH += unix/netbsd
+	}
+
 	openbsd-* {
 		VPATH       += unix/openbsd
 		INCLUDEPATH += unix/openbsd
