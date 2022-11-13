$NetBSD$

# Silence warnings

--- src/io/bead3d_cmd.cpp.orig	2022-11-12 15:14:12 UTC
+++ src/io/bead3d_cmd.cpp
@@ -157,7 +157,7 @@ void getBead3dIdRange(stringstream& ss, int *id_vec,
   int ns=(*it_bead3d).nStack,i,j,k,i0,j0, flag0,flag1,flag2;
   string sdum,sdum0,sdum1;
   stringstream ss0;
-  size_t found; char *cdum;
+  size_t found; char *cdum = nullptr;
   
   id_vec[0]=0; id_vec[1]=ns-1; // default
   flag0=checkCommOptKey(ss,"bead3d_id",1); // priority ordered
