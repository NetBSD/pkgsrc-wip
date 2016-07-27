$NetBSD$

--- progress.c.orig	2016-07-27 09:17:40.624147412 +0000
+++ progress.c
@@ -7,6 +7,8 @@ char progress_RCSid[] = "Revision: 1.1 $
 
 #include "agm.h"
 
+#include <signal.h>
+
 void print_progress () {
   printf ("%02d\b\b", pct);
   fflush (stdout);
@@ -18,7 +20,7 @@ void arm_timer ()
   struct itimerval tmr;
 
   action.sa_handler = &print_progress;
-  action.sa_mask = 0;
+  sigemptyset(&action.sa_mask);
   action.sa_flags = 0;
   sigaction (SIGALRM, &action, NULL);
   
@@ -41,7 +43,7 @@ void disarm_timer ()
   setitimer (ITIMER_REAL, &tmr, NULL);
 
   action.sa_handler = SIG_DFL;
-  action.sa_mask = 0;
+  sigemptyset(&action.sa_mask);
   action.sa_flags = 0;
   sigaction (SIGALRM, &action, NULL);
 }
