$NetBSD: patch-Test_mtest.c,v 1.1 2012/10/15 22:48:46 asau Exp $

--- Test/mtest.c.orig	1998-09-21 12:59:52.000000000 +0000
+++ Test/mtest.c
@@ -54,6 +54,7 @@ main(int argc, char *argv[])
   printf("**********************************************************************\n");
 
   GKfree(&graph.xadj, &graph.adjncy, &graph.vwgt, &graph.adjwgt, LTERM);
+  exit(0);
 }  
 
 
