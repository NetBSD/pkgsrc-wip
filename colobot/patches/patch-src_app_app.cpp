$NetBSD$
--- ./src/app/app.cpp.orig	2018-03-11 12:40:22.438785848 -0700
+++ ./src/app/app.cpp	2018-03-11 12:40:34.907176246 -0700
@@ -264,7 +264,7 @@
 
     int c = 0;
     int index = -1;
-    while ((c = getopt_long_only(argc, argv, "", options, &index)) != -1)
+    while ((c = getopt_long(argc, argv, "", options, &index)) != -1)
     {
         if (c == '?')
         {
