$NetBSD$

--- src/main/java/com/google/devtools/build/lib/jni/JniLoader.java.orig	2023-11-30 05:46:49.398016529 +0000
+++ src/main/java/com/google/devtools/build/lib/jni/JniLoader.java
@@ -39,6 +39,7 @@ public final class JniLoader {
       switch (OS.getCurrent()) {
         case LINUX:
         case FREEBSD:
+        case NETBSD:
         case OPENBSD:
         case UNKNOWN:
           loadLibrary("main/native/libunix_jni.so");
