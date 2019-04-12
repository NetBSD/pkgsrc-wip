$NetBSD$

	remove inadequate clutter in status messages

--- core/src/dird/migrate.cc.orig	2019-02-01 07:15:47.112695213 +0000
+++ core/src/dird/migrate.cc
@@ -1723,7 +1723,9 @@ static inline void GenerateMigrateSummar
            "  Last Volume Bytes:      %s (%sB)\n"
            "  SD Errors:              %d\n"
            "  SD termination status:  %s\n"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
            BAREOS, my_name, VERSION, LSMDATE,
            HOST_OS, DISTNAME, DISTVER,
@@ -1759,7 +1761,9 @@ static inline void GenerateMigrateSummar
            edit_uint64_with_suffix(mr->VolBytes, ec5),
            jcr->SDErrors,
            sd_term_msg,
+#ifndef NO_ADV
            BAREOS_JOBLOG_MESSAGE,
+#endif
            term_code);
    } else {
       /*
@@ -1774,7 +1778,9 @@ static inline void GenerateMigrateSummar
            "  End time:               %s\n"
            "  Elapsed time:           %s\n"
            "  Priority:               %d\n"
+#ifndef NO_ADV
            "  Bareos binary info:     %s\n"
+#endif
            "  Termination:            %s\n\n"),
            BAREOS, my_name, VERSION, LSMDATE,
            HOST_OS, DISTNAME, DISTVER,
@@ -1785,7 +1791,9 @@ static inline void GenerateMigrateSummar
            edt,
            edit_utime(RunTime, elapsed, sizeof(elapsed)),
            jcr->JobPriority,
+#ifndef NO_ADV
            BAREOS_JOBLOG_MESSAGE,
+#endif
            term_code);
    }
 }
