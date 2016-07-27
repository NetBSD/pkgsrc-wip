$NetBSD$

--- agm.h.orig	2016-07-27 20:00:36.476968160 +0000
+++ agm.h
@@ -134,5 +134,10 @@ extern struct wnode *lstart, *lend;
 extern char main_RCSid[], gobble_RCSid[], listfuncs_RCSid[], output_RCSid[],
             process_RCSid[], sort_RCSid[], wordfuncs_RCSid[], progress_RCSid[];
 
-extern void copysmall();
-extern void arm_timer(), disarm_timer();
+extern void copysmall(char *, char *);
+extern void arm_timer(void), disarm_timer(void);
+extern int contains (char *, char *, unsigned int *);
+extern int addword (char *, struct wnode **, struct wnode **);
+estern int eliminate (char *, char *, char *);
+extern void print_prevs (int);
+extern void destroy_list (struct wnode *, struct wnode *);
