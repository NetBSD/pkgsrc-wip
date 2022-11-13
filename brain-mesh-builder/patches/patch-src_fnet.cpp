$NetBSD$

# Silence warnings

--- src/fnet.cpp.orig	2021-04-15 21:30:36 UTC
+++ src/fnet.cpp
@@ -66,7 +66,7 @@ fnet::fnet(img *img0, int iDiam,unsigned char pxlCut,s
   
   vector<vector<pair<int,int>>> cluster;
   vector<pair<double,double>>::iterator it,jt;
-  vector<pair<int,int>>:: iterator iit; 
+  // Unused vector<pair<int,int>>:: iterator iit; 
   
   // set tag and img global vars
   bead_tag=""; // no corresponding bead
@@ -1766,7 +1766,7 @@ void fnet::writeCor(string fname, string fmt, string o
   if (fmt=="pdb") fprintf(ff,"ENDMDL\n");
   fclose(ff);
   
-  delete filSeq; delete x; delete y; delete weight;
+  delete [] filSeq; delete [] x; delete [] y; delete [] weight;
 }
 
 /************************************************************************/
@@ -1780,7 +1780,7 @@ void fnet::writeData(string fname, string bd_fname, FI
   multimap<int,int>::iterator it;
   pair<multimap<int,int>::iterator,multimap<int,int>::iterator> it_range; 
   
-  vector<bead>::iterator it_bead;
+  // Unused vector<bead>::iterator it_bead;
   bool bd_newFile = (bd_dat == NULL);
   string bd_datname; 
   
