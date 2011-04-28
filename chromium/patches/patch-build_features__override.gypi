$NetBSD: patch-build_features__override.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- build/features_override.gypi.orig	2011-04-13 08:01:33.000000000 +0000
+++ build/features_override.gypi
@@ -72,7 +72,7 @@
     'enable_svg%': '<(enable_svg)',
     'enable_touch_events%': '<(enable_touch_events)',
     'conditions': [
-      ['(OS=="win" or OS=="linux" or OS=="mac") and use_accelerated_compositing==1', {
+      ['(OS=="win" or OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="mac") and use_accelerated_compositing==1', {
         'feature_defines': [
           'WTF_USE_ACCELERATED_COMPOSITING=1',
           'ENABLE_3D_RENDERING=1',
