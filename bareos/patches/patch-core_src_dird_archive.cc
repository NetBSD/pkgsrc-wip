$NetBSD$

	Remove inadequate clutter in production messages

--- core/src/dird/archive.cc.orig	2019-02-01 07:12:55.170024679 +0000
+++ core/src/dird/archive.cc
@@ -117,7 +117,9 @@ void ArchiveCleanup(JobControlRecord *jc
         "  Scheduled time:         %s\n"
         "  Start time:             %s\n"
         "  End time:               %s\n"
+#ifndef NO_ADV
         "  Bareos binary info:     %s\n"
+#endif
         "  Termination:            %s\n\n"),
         edt,
         jcr->jr.JobId,
@@ -125,7 +127,9 @@ void ArchiveCleanup(JobControlRecord *jc
         schedt,
         sdt,
         edt,
+#ifndef NO_ADV
         BAREOS_JOBLOG_MESSAGE,
+#endif
         TermMsg);
 
    Dmsg0(debuglevel, "Leave ArchiveCleanup()\n");
