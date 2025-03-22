$NetBSD$

NetBSD doesn't support getopt_long_only.

--- settings.cc.orig	2025-02-23 20:39:21.000000000 +0000
+++ settings.cc
@@ -1256,7 +1256,7 @@ void getOptions(int argc, char *argv[])
 
   errno=0;
   for(;;) {
-    int c = getopt_long_only(argc,argv,
+    int c = getopt_long(argc,argv,
                              optstring.c_str(), longopts, &long_index);
     if (c == -1)
       break;
