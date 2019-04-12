$NetBSD$

	remove inadequate clutter in status messages

--- core/src/dird/verify.cc.orig	2019-02-01 07:18:21.139427739 +0000
+++ core/src/dird/verify.cc
@@ -569,7 +569,9 @@ void VerifyCleanup(JobControlRecord *jcr
            "  Non-fatal FD errors:    %d\n"
            "  FD termination status:  %s\n"
            "  SD termination status:  %s\n"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
            BAREOS, my_name, VERSION, LSMDATE,
            HOST_OS, DISTNAME, DISTVER,
@@ -587,7 +589,9 @@ void VerifyCleanup(JobControlRecord *jcr
            jcr->JobErrors,
            fd_term_msg,
            sd_term_msg,
+#ifndef NO_ADV
            BAREOS_JOBLOG_MESSAGE,
+#endif
            TermMsg);
       break;
    default:
@@ -605,7 +609,9 @@ void VerifyCleanup(JobControlRecord *jcr
            "  Files Examined:         %s\n"
            "  Non-fatal FD errors:    %d\n"
            "  FD termination status:  %s\n"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
            BAREOS, my_name, VERSION, LSMDATE,
            HOST_OS, DISTNAME, DISTVER,
@@ -621,7 +627,9 @@ void VerifyCleanup(JobControlRecord *jcr
            edit_uint64_with_commas(jcr->JobFiles, ec1),
            jcr->JobErrors,
            fd_term_msg,
+#ifndef NO_ADV
            BAREOS_JOBLOG_MESSAGE,
+#endif
            TermMsg);
       break;
    }
