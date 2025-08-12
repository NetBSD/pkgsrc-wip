$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/javafx/tk/quantum/WindowStage.java.orig	2024-10-21 13:27:30.874992552 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/tk/quantum/WindowStage.java
@@ -440,7 +440,7 @@ public class WindowStage extends GlassSt
         } else if (PlatformUtil.isWindows()) { //Windows Sized Icons
             SMALL_ICON_HEIGHT = 32;
             SMALL_ICON_WIDTH = 32;
-        } else if (PlatformUtil.isLinux()) { //Linux icons
+        } else if (PlatformUtil.isLinux() || PlatformUtil.isNetBSD()) { //Linux icons
             SMALL_ICON_HEIGHT = 128;
             SMALL_ICON_WIDTH = 128;
         }
