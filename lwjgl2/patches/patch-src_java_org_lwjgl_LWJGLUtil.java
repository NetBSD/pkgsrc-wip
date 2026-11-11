$NetBSD$

Detect `os.name=NetBSD` appropriately.

--- src/java/org/lwjgl/LWJGLUtil.java.orig	2026-11-11 02:52:17.131751206 +0000
+++ src/java/org/lwjgl/LWJGLUtil.java
@@ -272,7 +272,7 @@ public class LWJGLUtil {
 		final String osName = getPrivilegedProperty("os.name");
 		if ( osName.startsWith("Windows") )
 			PLATFORM = PLATFORM_WINDOWS;
-		else if ( osName.startsWith("Linux") || osName.startsWith("FreeBSD") || osName.startsWith("OpenBSD") || osName.startsWith("SunOS") || osName.startsWith("Unix") )
+		else if ( osName.startsWith("Linux") || osName.startsWith("FreeBSD") || osName.startsWith("NetBSD") || osName.startsWith("OpenBSD") || osName.startsWith("SunOS") || osName.startsWith("Unix") )
 			PLATFORM = PLATFORM_LINUX;
 		else if ( osName.startsWith("Mac OS X") || osName.startsWith("Darwin") )
 			PLATFORM = PLATFORM_MACOSX;
