$NetBSD$

	Remove inadequate clutter in production messages

--- core/src/dird/backup.cc.orig	2019-02-01 07:24:50.329931934 +0000
+++ core/src/dird/backup.cc
@@ -1216,7 +1216,9 @@ void GenerateBackupSummary(JobControlRec
         "  Last Volume Bytes:      %s (%sB)\n"
         "%s"                                        /* Daemon status info */
         "%s"                                        /* SecureErase status */
+#ifndef NO_ADV
         "  Bareos binary info:     %s\n"
+#endif
         "  Termination:            %s\n\n"),
         BAREOS, my_name, VERSION, LSMDATE,
         HOST_OS, DISTNAME, DISTVER,
@@ -1244,7 +1246,9 @@ void GenerateBackupSummary(JobControlRec
         edit_uint64_with_suffix(mr.VolBytes, ec8),
         daemon_status.c_str(),
         secure_erase_status.c_str(),
+#ifndef NO_ADV
         BAREOS_JOBLOG_MESSAGE,
+#endif
         TermMsg);
 }
 } /* namespace directordaemon */
