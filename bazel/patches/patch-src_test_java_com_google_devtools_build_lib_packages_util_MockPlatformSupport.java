$NetBSD$

--- src/test/java/com/google/devtools/build/lib/packages/util/MockPlatformSupport.java.orig	2023-11-28 16:47:15.246726723 +0000
+++ src/test/java/com/google/devtools/build/lib/packages/util/MockPlatformSupport.java
@@ -136,6 +136,10 @@ public class MockPlatformSupport {
         "    constraint_setting = ':os',",
         ")",
         "constraint_value(",
+        "    name = 'netbsd',",
+        "    constraint_setting = ':os',",
+        ")",
+        "constraint_value(",
         "    name = 'openbsd',",
         "    constraint_setting = ':os',",
         ")");
