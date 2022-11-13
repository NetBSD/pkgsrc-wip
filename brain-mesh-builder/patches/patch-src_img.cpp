$NetBSD$

# Silence warnings

--- src/img.cpp.orig	2022-11-12 14:21:36 UTC
+++ src/img.cpp
@@ -1109,7 +1109,7 @@ void img::thresholdAuto(double cutoff, int nbin, strin
   unsigned char **pxl_tmp=new unsigned char*[rows];
   int i,j,i0=0,i1=0,i2;
   vector<int> local_min, local_max; // local histo min/max
-  vector<int>::iterator it;
+  // Unused vector<int>::iterator it;
   
   string sdum=(tag1=="")?tag:tag1;
 
@@ -1216,7 +1216,7 @@ void img::thresholdHisto(double *cutoff, int nbin, str
   unsigned char **pxl_tmp=new unsigned char*[rows];
   int i,j,i0,i2,imax;
   vector<int> local_min; 
-  vector<int>::iterator it;
+  // Unused vector<int>::iterator it;
   
   string sdum=(tag1=="")?tag:tag1;
 
@@ -1443,7 +1443,7 @@ vector<img>::iterator findImg(string tag)
 void getImgTagRange(stringstream& ss, string *svec)
 {
   string sdum,sdum0,sdum1;
-  size_t found;  char *cdum;
+  size_t found;  char *cdum = nullptr;
   int i,j,k;
   
   svec[0]=vimg.begin()->tag; svec[1]=vimg.rbegin()->tag; // default
@@ -1497,7 +1497,7 @@ void mergeImg(img *img0, img *img1, string mode,string
      If tag2 given create new img, img0 and img1 will be unmodified. */
   
   int i,j,k=0;
-  double avgdum,sddum,rdum;
+  double sddum, rdum;	// Unused avgdum
   unsigned char **pxl_tmp;
   vector<img>::iterator it_img,it_img1;
   string sdum=(tag2=="")?img0->tag:tag2; 
@@ -1508,7 +1508,8 @@ void mergeImg(img *img0, img *img1, string mode,string
   if ((img1->rows!=img0->rows)||(img1->columns!=img0->columns))
     error_dodri("Size of two images do not match.");
 
-  avgdum=sddum=0; 
+  // Unused avgdum=0
+  sddum=0; 
   if (tag2=="") tag2=img0->tag; // merge into img1 by default
   it_img= findImg(tag2);
   if (it_img != vimg.end()) {
@@ -1537,7 +1538,7 @@ void mergeImg(img *img0, img *img1, string mode,string
 	if (k>255) k=255;
 	if (k<0) k=abs(k);
 	it_img->pxl_gray[i][j]=(unsigned char)k;
-	rdum=(double)k; avgdum+=rdum; sddum+=rdum*rdum;
+	rdum=(double)k; sddum+=rdum*rdum; // Unused avgdum+=rdum;
       }
     }
     cout<<"    Image "<<tag2<<" modified."<<endl;
