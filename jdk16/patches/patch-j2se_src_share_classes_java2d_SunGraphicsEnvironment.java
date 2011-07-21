$NetBSD: patch-j2se_src_share_classes_java2d_SunGraphicsEnvironment.java,v 1.1 2011/07/21 16:05:11 ftigeot Exp $

--- j2se/src/share/classes/sun/java2d/SunGraphicsEnvironment.java.orig	2011-07-21 13:25:18 +0000
+++ j2se/src/share/classes/sun/java2d/SunGraphicsEnvironment.java
@@ -128,6 +128,8 @@ public abstract class SunGraphicsEnviron
 	        String osName = System.getProperty("os.name");
 		if ("Linux".equals(osName)) {
 		    isLinuxOrBSD = true;
+		} else if ("DragonFly".equals(osName)) {
+		    isLinuxOrBSD = true;
 		} else if ("FreeBSD".equals(osName)) {
 		    isLinuxOrBSD = true;
 		} else if ("NetBSD".equals(osName)) {
