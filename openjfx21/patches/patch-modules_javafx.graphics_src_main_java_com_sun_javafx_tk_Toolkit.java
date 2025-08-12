$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/javafx/tk/Toolkit.java.orig	2024-10-21 13:16:03.339570009 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/tk/Toolkit.java
@@ -186,6 +186,8 @@ public abstract class Toolkit {
             return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isLinux()) {
             return DEFAULT_TOOLKIT;
+        } else if (PlatformUtil.isNetBSD()) {
+            return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isIOS()) {
             return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isAndroid()) {
