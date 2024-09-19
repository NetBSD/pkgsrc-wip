$NetBSD$

Add some libraries to the linker. And remove unneeded.

--- goldendict.pro	2016-04-26 16:32:50.000000000 +0000
+++ goldendict.pro
@@ -44,7 +44,12 @@ RCC_DIR = build
 LIBS += \
         -lz \
         -lbz2 \
-        -llzo2
+        -llzo2 \
+        -lexecinfo \
+        -lintl \
+        -lavutil \
+        -lavformat \
+        -lavcodec
 
 !isEmpty(DISABLE_INTERNAL_PLAYER): DEFINES += DISABLE_INTERNAL_PLAYER
 
@@ -157,9 +162,6 @@ unix:!mac {
         hunspell
     isEmpty(DISABLE_INTERNAL_PLAYER) {
         PKGCONFIG += ao \
-            libavutil \
-            libavformat \
-            libavcodec
     }
     arm {
         LIBS += -liconv
