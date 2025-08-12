$NetBSD$

--- modules/javafx.base/src/main/java/com/sun/javafx/PlatformUtil.java.orig	2024-10-21 13:17:03.235566355 +0000
+++ modules/javafx.base/src/main/java/com/sun/javafx/PlatformUtil.java
@@ -85,6 +85,7 @@ public class PlatformUtil {
     private static final boolean WINDOWS_7_OR_LATER = WINDOWS && versionNumberGreaterThanOrEqualTo(6.1f);
     private static final boolean MAC = os.startsWith("Mac");
     private static final boolean LINUX = os.startsWith("Linux") && !ANDROID;
+    private static final boolean NETBSD = os.startsWith("NetBSD");
     private static final boolean SOLARIS = os.startsWith("SunOS");
     private static final boolean IOS = os.startsWith("iOS");
     private static final boolean STATIC_BUILD = "Substrate VM".equals(System.getProperty("java.vm.name"));
@@ -141,6 +142,10 @@ public class PlatformUtil {
         return LINUX;
     }
 
+    public static boolean isNetBSD(){
+        return NETBSD;
+    }
+
     public static boolean useEGL() {
         return useEGL;
     }
@@ -170,7 +175,7 @@ public class PlatformUtil {
      * Returns true if the operating system is a form of Linux or Solaris
      */
     public static boolean isUnix(){
-        return LINUX || SOLARIS;
+        return LINUX || SOLARIS || NETBSD;
     }
 
     /**
