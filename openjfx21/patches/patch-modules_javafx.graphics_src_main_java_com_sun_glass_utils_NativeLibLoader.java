$NetBSD$

--- modules/javafx.graphics/src/main/java/com/sun/glass/utils/NativeLibLoader.java.orig	2024-08-20 17:07:03.000000000 +0000
+++ modules/javafx.graphics/src/main/java/com/sun/glass/utils/NativeLibLoader.java
@@ -363,6 +363,8 @@ public class NativeLibLoader {
             relativeDir = "lib";
         } else if (PlatformUtil.isLinux()) {
             relativeDir = "lib";
+        } else if (PlatformUtil.isNetBSD()) {
+            relativeDir = "lib";
         }
 
         // Location of native libraries relative to java.home
@@ -383,6 +385,8 @@ public class NativeLibLoader {
             relativeDir = ".";
         } else if (PlatformUtil.isLinux()) {
             relativeDir = ".";
+        } else if (PlatformUtil.isNetBSD()) {
+            relativeDir = ".";
         }
 
         // Location of native libraries relative to jar file
@@ -421,6 +425,9 @@ public class NativeLibLoader {
                 } else if (PlatformUtil.isLinux()) {
                     libPrefix = "lib";
                     libSuffix = ".so";
+                } else if (PlatformUtil.isNetBSD()) {
+                    libPrefix = "lib";
+                    libSuffix = ".so";
                 }
             }
 
