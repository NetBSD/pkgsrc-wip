$NetBSD$

--- agm.h.orig	1998-03-18 01:02:29.000000000 +0000
+++ agm.h
@@ -134,5 +134,5 @@ extern struct wnode *lstart, *lend;
 extern char main_RCSid[], gobble_RCSid[], listfuncs_RCSid[], output_RCSid[],
             process_RCSid[], sort_RCSid[], wordfuncs_RCSid[], progress_RCSid[];
 
-extern void copysmall();
-extern void arm_timer(), disarm_timer();
+extern void copysmall(char *, char *);
+extern void arm_timer(void), disarm_timer(void);
