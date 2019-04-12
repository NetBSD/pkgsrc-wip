$NetBSD$

	Remove inadequate clutter in production messages

--- core/src/dird/consolidate.cc.orig	2019-02-01 07:25:12.470246640 +0000
+++ core/src/dird/consolidate.cc
@@ -350,7 +350,9 @@ void ConsolidateCleanup(JobControlRecord
         "  Scheduled time:         %s\n"
         "  Start time:             %s\n"
         "  End time:               %s\n"
+#ifndef NO_ADV
         "  Bareos binary info:     %s\n"
+#endif
         "  Termination:            %s\n\n"),
         edt,
         jcr->jr.JobId,
@@ -358,7 +360,9 @@ void ConsolidateCleanup(JobControlRecord
         schedt,
         sdt,
         edt,
+#ifndef NO_ADV
         BAREOS_JOBLOG_MESSAGE,
+#endif
         TermMsg);
 
    Dmsg0(debuglevel, "Leave ConsolidateCleanup()\n");
