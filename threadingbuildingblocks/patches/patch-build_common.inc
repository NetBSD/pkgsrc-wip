$NetBSD$

--- build/common.inc.orig	2016-09-22 10:28:03.000000000 +0000
+++ build/common.inc
@@ -36,6 +36,9 @@ ifndef tbb_os
   ifeq ($(OS), Darwin)
     export tbb_os=macos
   endif
+  ifeq ($(OS), NetBSD)
+    export tbb_os=netbsd
+  endif
 
 endif # !tbb_os
 
