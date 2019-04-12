$NetBSD$

	remove inadequate clutter in status messages

--- core/src/dird/restore.cc.orig	2019-02-01 07:17:27.460662966 +0000
+++ core/src/dird/restore.cc
@@ -583,7 +583,9 @@ void GenerateRestoreSummary(JobControlRe
            "  Bytes Restored:         %s\n"
            "  Rate:                   %.1f KB/s\n"
            "  SD termination status:  %s\n"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
            BAREOS, my_name, VERSION, LSMDATE,
            HOST_OS, DISTNAME, DISTVER,
@@ -598,7 +600,9 @@ void GenerateRestoreSummary(JobControlRe
            edit_uint64_with_commas(jcr->jr.JobBytes, ec3),
            (float)kbps,
            sd_term_msg,
+#ifndef NO_ADV
            BAREOS_JOBLOG_MESSAGE,
+#endif
            TermMsg);
       break;
    default:
@@ -631,7 +635,9 @@ void GenerateRestoreSummary(JobControlRe
            "  FD termination status:  %s\n"
            "  SD termination status:  %s\n"
            "%s"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
            BAREOS, my_name, VERSION, LSMDATE,
            HOST_OS, DISTNAME, DISTVER,
@@ -649,7 +655,9 @@ void GenerateRestoreSummary(JobControlRe
            fd_term_msg,
            sd_term_msg,
            secure_erase_status.c_str(),
+#ifndef NO_ADV
            BAREOS_JOBLOG_MESSAGE,
+#endif
            TermMsg);
       break;
    }
