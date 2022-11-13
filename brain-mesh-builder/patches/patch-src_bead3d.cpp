$NetBSD$

# Silence warnings

--- src/bead3d.cpp.orig	2022-11-12 14:57:13 UTC
+++ src/bead3d.cpp
@@ -94,7 +94,7 @@ int bead3d::beadTag2Id(string sdum)
      Returns: id number or -1 if tag not found */
 
   int i,j;
-  vector<bead>::iterator it_bead;
+  // Unused vector<bead>::iterator it_bead;
   j=-1;
   for (i=0;i<nStack;i++) {
     if (bead_stack[i].tag==sdum) {j=i; break;}
