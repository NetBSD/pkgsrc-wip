$NetBSD: patch-programs_dtpdmd_manager.c,v 1.1 2014/07/27 07:44:56 obache Exp $

* `now' is used with time(3) 

--- programs/dtpdmd/manager.c.orig	2014-03-01 22:48:49.000000000 +0000
+++ programs/dtpdmd/manager.c
@@ -642,7 +642,7 @@ void mgr_launch_reply( XpPdmServiceRec *
     XEvent reply;
     Status status;
     FILE   *errlog;
-    long   now;
+    time_t now;
     char   *eec;
 
     Atom    tmpa;
@@ -891,7 +891,7 @@ Bool has_exec_token( XpPdmServiceRec *re
 void mgr_shutdown_scan()
 {
     int        i;
-    long       now;
+    time_t     now;
     FILE       *errlog;
     static int errlog_problem_notice = 0;
     Bool       shutdown_time;
