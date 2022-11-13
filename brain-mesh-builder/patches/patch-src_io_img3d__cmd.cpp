$NetBSD$

# Silence warnings

--- src/io/img3d_cmd.cpp.orig	2022-11-12 15:08:11 UTC
+++ src/io/img3d_cmd.cpp
@@ -256,7 +256,7 @@ void getImg3dIdRange(stringstream& ss, int *id_vec,
   int ns=(*it_img3d).nStack,i,j,k,i0,j0, flag0,flag1,flag2;
   string sdum,sdum0,sdum1;
   stringstream ss0;
-  size_t found; char *cdum;
+  size_t found; char *cdum = nullptr;
   
   id_vec[0]=0; id_vec[1]=ns-1; // default
   flag0=checkCommOptKey(ss,"img3d_id",1); // priority ordered
