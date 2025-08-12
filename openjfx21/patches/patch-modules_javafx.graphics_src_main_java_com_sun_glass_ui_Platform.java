$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/glass/ui/Platform.java.orig	2024-10-21 13:22:39.527745356 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/glass/ui/Platform.java
@@ -68,6 +68,8 @@ final class Platform {
                 type = WINDOWS;
             } else if (PlatformUtil.isLinux()) {
                 type = GTK;
+            } else if (PlatformUtil.isNetBSD()) {
+                type = GTK;
             } else if (PlatformUtil.isIOS()) {
                 type = IOS;
             }
