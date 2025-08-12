$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/prism/impl/PrismSettings.java.orig	2024-10-21 13:23:22.340848969 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/prism/impl/PrismSettings.java
@@ -217,6 +217,8 @@ public final class PrismSettings {
                     tryOrderArr = new String[] { "es2" };
             } else if (PlatformUtil.isLinux()) {
                 tryOrderArr = new String[] { "es2", "sw" };
+            } else if (PlatformUtil.isNetBSD()) {
+                tryOrderArr = new String[] { "es2", "sw" };
             } else {
                 tryOrderArr = new String[] { "sw" };
             }
