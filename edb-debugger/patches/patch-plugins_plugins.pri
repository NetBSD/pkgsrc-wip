$NetBSD$

--- plugins/plugins.pri.orig	2013-07-23 02:30:10.000000000 +0000
+++ plugins/plugins.pri
@@ -23,10 +23,11 @@ unix {
 	INCLUDEPATH += $$LEVEL/include $$LEVEL/include/os/unix
 	
 	# OS include paths
-	linux-*   : INCLUDEPATH += $$LEVEL/include/os/unix/linux
-	openbsd-* : INCLUDEPATH += $$LEVEL/include/os/unix/openbsd /usr/local/include
 	freebsd-* : INCLUDEPATH += $$LEVEL/include/os/unix/freebsd
+	linux-*   : INCLUDEPATH += $$LEVEL/include/os/unix/linux
 	macx-*    : INCLUDEPATH += $$LEVEL/include/os/unix/osx /opt/local/include
+	netbsd-*  : INCLUDEPATH += $$LEVEL/include/os/unix/netbsd
+	openbsd-* : INCLUDEPATH += $$LEVEL/include/os/unix/openbsd /usr/local/include
 
 	# arch include paths
 	macx {
@@ -34,7 +35,7 @@ unix {
 		include(plugins-x86_64.pri)
 	}
 
-	!macx:contains(QMAKE_HOST.arch, x86_64) {
+	!macx:contains(QMAKE_HOST.arch, x86_64|amd64) {
 		INCLUDEPATH += $$LEVEL/include/arch/x86_64
 		include(plugins-x86_64.pri)
 	}
