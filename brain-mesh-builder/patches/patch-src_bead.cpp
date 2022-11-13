$NetBSD$

# Silence warnings

--- src/bead.cpp.orig	2022-11-12 14:53:55 UTC
+++ src/bead.cpp
@@ -469,7 +469,7 @@ int bead::getBeadDir(double rCut, multimap<int,array<d
   MinMax(i,rvec,&ix,&iy,&sx,&sy);
   cout<<"    Min/Max of chi^2: "<<sx<<"  "<<sy<<endl;
 
-  delete rvec;
+  delete[] rvec;
   for (i=0;i<3;i++) delete [] mask[i];
   delete [] mask;
   
