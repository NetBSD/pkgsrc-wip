$NetBSD$

popcount() is declared in <strings.h> included from <string.h>.

--- cmdline/bgolly.cpp.orig	2018-01-21 02:19:18.000000000 +0000
+++ cmdline/bgolly.cpp
@@ -122,7 +122,7 @@ struct options {
 bigint maxgen = -1, inc = 0 ;
 int maxmem = 256 ;
 int hyperxxx ;   // renamed hyper to avoid conflict with windows.h
-int render, autofit, quiet, popcount, progress ;
+int render, autofit, quiet, xpopcount, progress ;
 int hashlife ;
 char *algoName = 0 ;
 int verbose ;
@@ -152,7 +152,7 @@ options options[] = {
   { "-t", "--timeline", "Use timeline", 'b', &timeline },
   { "",   "--render", "Render (benchmarking)", 'b', &render },
   { "",   "--progress", "Render during progress dialog (debugging)", 'b', &progress },
-  { "",   "--popcount", "Popcount (benchmarking)", 'b', &popcount },
+  { "",   "--xpopcount", "Popcount (benchmarking)", 'b', &xpopcount },
   { "",   "--scale", "Rendering scale", 's', &renderscale },
 //{ "",   "--stepthreshold", "Stepsize >= gencount/this (default 1)",
 //                                                          'i', &stepthresh },
@@ -648,7 +648,7 @@ case 's':
          } else
             cout << endl ;
       }
-      if (popcount)
+      if (xpopcount)
          imp->getPopulation() ;
       if (autofit)
         imp->fit(viewport, 1) ;
