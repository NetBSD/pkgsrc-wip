$NetBSD$

--- vm/src/any/zone/fprofiler.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/zone/fprofiler.cpp
@@ -15,7 +15,7 @@
 # define PROFIL_SCALE   (0x10000 >> SHIFT)   /* see profil(2) man page */
 # define scale(offset)  ((offset >> SHIFT) / sizeof(PCounter))
 
-# if  TARGET_OS_VERSION == MACOSX_VERSION   &&  OSX_RELEASE >= MOUNTAIN_LION_RELEASE 
+# if  (TARGET_OS_VERSION == MACOSX_VERSION   &&  OSX_RELEASE >= MOUNTAIN_LION_RELEASE)
 
 extern "C" int profil( char* /*buf*/,
             size_t   /*bufsiz*/,
@@ -24,7 +24,7 @@ extern "C" int profil( char* /*buf*/,
   fatal("unimp mac");
   return 0;
 }
-# elif TARGET_OS_FAMILY == UNIX_FAMILY
+# elif TARGET_OS_FAMILY == UNIX_FAMILY && !(TARGET_OS_VERSION == NETBSD_VERSION)
 /* Pick this up from header file:
   extern "C" void profil(unsigned short *buf,
                          unsigned int bufsiz,
@@ -337,7 +337,7 @@ oop PrintFlatProfile_prim(oop r, smi lin
 // need this entry point either way
 
 void SelfFlatProfile(bool on) {
-  # if TARGET_OS_VERSION == MACOSX_VERSION
+  # if TARGET_OS_VERSION == MACOSX_VERSION || TARGET_OS_VERSION == NETBSD_VERSION
     typedef  char *           buf_t;
   # else // ! MACOSX_VERSION
     typedef unsigned short *  buf_t;
@@ -360,4 +360,3 @@ void SelfFlatProfile(bool on) {
       warning("_FlatProfile: only works with unprofiled VM");
   # endif
 }
-
