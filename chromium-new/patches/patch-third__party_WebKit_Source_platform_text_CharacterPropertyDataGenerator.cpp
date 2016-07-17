$NetBSD$

--- third_party/WebKit/Source/platform/text/CharacterPropertyDataGenerator.cpp.orig	2016-06-24 01:02:46.000000000 +0000
+++ third_party/WebKit/Source/platform/text/CharacterPropertyDataGenerator.cpp
@@ -11,12 +11,12 @@
 #include <cassert>
 #include <cstring>
 #include <stdio.h>
-#if !defined(USING_SYSTEM_ICU)
+#if !defined(__FreeBSD__)
 #define MUTEX_H // Prevent compile failure of utrie2.h on Windows
 #include <utrie2.h>
 #endif
 
-#if defined(USING_SYSTEM_ICU)
+#if defined(__FreeBSD__)
 static void generate(FILE*)
 {
 }
