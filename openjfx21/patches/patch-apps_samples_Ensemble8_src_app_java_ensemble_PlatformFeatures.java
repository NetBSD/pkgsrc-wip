$NetBSD$

--- apps/samples/Ensemble8/src/app/java/ensemble/PlatformFeatures.java.orig	2024-08-20 17:07:03.000000000 +0000
+++ apps/samples/Ensemble8/src/app/java/ensemble/PlatformFeatures.java
@@ -43,6 +43,7 @@ public class PlatformFeatures {
     private static final boolean WINDOWS = os.startsWith("Windows");
     private static final boolean MAC = os.startsWith("Mac");
     private static final boolean LINUX = os.startsWith("Linux");
+    private static final boolean NETBSD = os.startsWith("NetBSD");
     private static final boolean ANDROID = "android".equals(System.getProperty("javafx.platform")) || "Dalvik".equals(System.getProperty("java.vm.name"));
     private static final boolean IOS = os.startsWith("iOS");
     private static final boolean EMBEDDED = "arm".equals(arch) && !IOS && !ANDROID;
