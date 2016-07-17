$NetBSD$

--- skia/skia_common.gypi.orig	2016-06-24 01:02:27.000000000 +0000
+++ skia/skia_common.gypi
@@ -65,7 +65,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
