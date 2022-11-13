$NetBSD$

# Silence warnings

--- src/surface.cpp.orig	2022-11-12 15:10:21 UTC
+++ src/surface.cpp
@@ -520,8 +520,8 @@ void surface::registerPent()
   it_fnet3d=findFnet3d(&vfnet3d,this->fnet3d_tag); 
 
   //for bead insert
-  vector<bead>::iterator it_bead;
-  vector<fnet>::iterator it_fnet;  
+  // Unused vector<bead>::iterator it_bead;
+  // Unused vector<fnet>::iterator it_fnet;  
   vector<bead3d>::iterator it_bead3d;
   it_bead3d=findBead3d(&vbead3d,it_fnet3d->bead3d_tag);
     
