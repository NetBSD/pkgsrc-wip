$NetBSD$

	Remove inadequate clutter in production messages

--- core/src/dird/admin.cc.orig	2019-01-31 11:39:26.000000000 +0000
+++ core/src/dird/admin.cc
@@ -118,7 +118,9 @@ void AdminCleanup(JobControlRecord *jcr,
         "  Scheduled time:         %s\n"
         "  Start time:             %s\n"
         "  End time:               %s\n"
+#ifndef NO_ADV
         "  Bareos binary info:     %s\n"
+#endif
         "  Termination:            %s\n\n"),
         edt,
         jcr->jr.JobId,
@@ -126,7 +128,9 @@ void AdminCleanup(JobControlRecord *jcr,
         schedt,
         sdt,
         edt,
+#ifndef NO_ADV
         BAREOS_JOBLOG_MESSAGE,
+#endif
         TermMsg);
 
    Dmsg0(debuglevel, "Leave AdminCleanup()\n");
