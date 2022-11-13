$NetBSD$

# Silence warnings

--- src/img3d.cpp.orig	2022-11-12 15:10:54 UTC
+++ src/img3d.cpp
@@ -147,7 +147,7 @@ int img3d::imgTag2Id(string sdum)
   */
   
   int i,j;
-  vector<img>::iterator it_img;
+  // Unused vector<img>::iterator it_img;
   j=-1;
   for (i=0;i<nStack;i++) {
     if (img_stack[i].tag==sdum) {j=i; break;}
