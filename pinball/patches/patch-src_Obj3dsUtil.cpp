$NetBSD$

--- src/Obj3dsUtil.cpp.orig	2003-11-20 16:46:17.000000000 +0000
+++ src/Obj3dsUtil.cpp
@@ -570,7 +570,7 @@ extern "C" {
     unsigned int i=0; FILE* f=0;
 
     f=fopen( filename, "wt");
-    if ( ! f ) return (int) f;
+    if ( ! f ) return (intptr_t) f;
     for(i=0; i < in->no; i++) {
       t = fprintObject( f, & (in->vo[i]) );
     }
@@ -585,7 +585,7 @@ extern "C" {
     FILE* f=0;
     //debugf("+saveObject %s\n",filename);
     f=fopen( filename, "wt");
-    if ( ! f ) return (int) f;
+    if ( ! f ) return (intptr_t) f;
     t = fprintObject( f, o);
     fclose(f);
     //debug("-saveObject");
