$NetBSD$

Detect `os.name=NetBSD` and handle appropriately.

--- src/java/org/lwjgl/util/applet/AppletLoader.java.orig	2026-11-11 02:53:21.978010095 +0000
+++ src/java/org/lwjgl/util/applet/AppletLoader.java
@@ -778,6 +778,8 @@ public class AppletLoader extends Applet
 			nativeJarList = getParameter("al_solaris");
 		} else if (osName.startsWith("FreeBSD")) {
 			nativeJarList = getParameter("al_freebsd");
+		} else if (osName.startsWith("NetBSD")) {
+			nativeJarList = getParameter("al_netbsd");
 		} else if (osName.startsWith("OpenBSD")) {
 			nativeJarList = getParameter("al_openbsd");
 		} else {
