$NetBSD: patch-actived_activedstats.c,v 1.1 2011/09/21 20:10:17 hfath Exp $

Make dumploads() and fprintloads() static, and add prototypes

--- actived/activedstats.c.orig	1997-10-20 20:34:37.000000000 +0000
+++ actived/activedstats.c
@@ -61,6 +61,9 @@ static u_long cexp[3] = {
         0.9944598480048967 * FSCALE,    /* exp(-1/180) */
 };
 
+static int dumploads(void);
+static void fprintloads(FILE *);
+
 
 /*
  * Compute a tenex style load average of a quantity on
@@ -69,8 +72,7 @@ static u_long cexp[3] = {
 static void
 loadav(struct loadavg *avg, int nrun)
 {
-        register int i;
-        register struct proc *p;
+        int i;
 
         for (i = 0; i < 3; i++)
                 avg->ldavg[i] = (cexp[i] * avg->ldavg[i] +
@@ -116,7 +118,7 @@ loads(int reader_count, int startup_coun
 	return(0);
 }
 
-int dumploads()
+static int dumploads(void)
 {
 	FILE *fp;
 
@@ -128,7 +130,7 @@ int dumploads()
 	return(0);
 }
 
-int
+static void
 fprintloads(FILE *fp)
 {
 	double avenrun[3];
