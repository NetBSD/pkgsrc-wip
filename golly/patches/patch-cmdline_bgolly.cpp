$NetBSD$

popcount() is declared in <strings.h> included from <string.h>.

--- cmdline/bgolly.cpp.orig	2017-08-19 04:39:59.000000000 +0000
+++ cmdline/bgolly.cpp
@@ -115,7 +115,7 @@ struct options {
 } ;
 bigint maxgen = -1, inc = 0 ;
 int maxmem = 256 ;
-int hyper, render, autofit, quiet, popcount, progress ;
+int hyper, render, autofit, quiet, xpopcount, progress ;
 int hashlife ;
 char *algoName = 0 ;
 int verbose ;
@@ -143,7 +143,7 @@ options options[] = {
   { "-t", "--timeline", "Use timeline", 'b', &timeline },
   { "",   "--render", "Render (benchmarking)", 'b', &render },
   { "",   "--progress", "Render during progress dialog (debugging)", 'b', &progress },
-  { "",   "--popcount", "Popcount (benchmarking)", 'b', &popcount },
+  { "",   "--popcount", "Popcount (benchmarking)", 'b', &xpopcount },
   { "",   "--scale", "Rendering scale", 's', &renderscale },
 //{ "",   "--stepthreshold", "Stepsize >= gencount/this (default 1)",
 //                                                          'i', &stepthresh },
@@ -627,7 +627,7 @@ case 's':
          else
             cout << endl ;
       }
-      if (popcount)
+      if (xpopcount)
          imp->getPopulation() ;
       if (autofit)
         imp->fit(viewport, 1) ;
