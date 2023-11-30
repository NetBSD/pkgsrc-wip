$NetBSD$

--- src/main/java/com/google/devtools/build/lib/bazel/repository/LocalConfigPlatformFunction.java.orig	2023-11-28 16:37:24.063463278 +0000
+++ src/main/java/com/google/devtools/build/lib/bazel/repository/LocalConfigPlatformFunction.java
@@ -135,6 +135,8 @@ public class LocalConfigPlatformFunction
         return "@platforms//os:osx";
       case FREEBSD:
         return "@platforms//os:freebsd";
+      case NETBSD:
+        return "@platforms//os:netbsd";
       case OPENBSD:
         return "@platforms//os:openbsd";
       case LINUX:
