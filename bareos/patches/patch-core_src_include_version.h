$NetBSD$

	Reduce clutter on production messages

--- core/src/include/version.h.orig	2019-02-13 14:25:55.000000000 +0000
+++ core/src/include/version.h
@@ -6,29 +6,33 @@
 #define LSMDATE "13Feb19"
 
 #ifndef BAREOS_BINARY_INFO
-#define BAREOS_BINARY_INFO "self-compiled"
+#define BAREOS_BINARY_INFO "pkgsrc-compiled"
 #endif
 
 #ifndef BAREOS_SERVICES_MESSAGE
-#define BAREOS_SERVICES_MESSAGE "self-compiled binaries are UNSUPPORTED by bareos.com.\nGet official binaries and vendor support on https://www.bareos.com"
+#define BAREOS_SERVICES_MESSAGE "pkgsrc-compiled binaries are UNSUPPORTED by bareos.com.\nGet official binaries and vendor support on https://www.bareos.com"
 #endif
 
 #ifndef BAREOS_JOBLOG_MESSAGE
-#define BAREOS_JOBLOG_MESSAGE "self-compiled: Get official binaries and vendor support on bareos.com"
+#define BAREOS_JOBLOG_MESSAGE "pkgsrc-compiled: Get official binaries and vendor support on bareos.com if this platform is supported"
 #endif
 
 
 
 
-#define PROG_COPYRIGHT "\n" \
-                       BAREOS_SERVICES_MESSAGE \
-                       "\n" \
+#ifndef NO_ADV
+#define PROG_COPYRIGHT_BSM "\n" \
+            BAREOS_SERVICES_MESSAGE \
+            "\n"
+#else
+#define PROG_COPYRIGHT_BSM 
+#endif
+#define PROG_COPYRIGHT PROG_COPYRIGHT_BSM \
                        "Copyright (C) 2013-2019 Bareos GmbH & Co. KG\n" \
                        "Copyright (C) %d-2012 Free Software Foundation Europe e.V.\n" \
                        "Copyright (C) 2010-2017 Planets Communications B.V.\n"
 #define BYEAR "2019"       /* year for copyright messages in programs */
 
-
 /*
    BAREOS® - Backup Archiving REcovery Open Sourced
 
