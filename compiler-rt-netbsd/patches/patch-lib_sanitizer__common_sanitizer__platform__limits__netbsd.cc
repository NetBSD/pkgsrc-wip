$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2018-04-25 21:13:40.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -15,9 +15,15 @@
 #include "sanitizer_platform.h"
 
 #if SANITIZER_NETBSD
+
+#define _KMEMUSER
+#define RAY_DO_SIGLEV
+
 #include <sys/param.h>
 #include <sys/types.h>
 
+#include <sys/sysctl.h>
+
 #include <altq/altq.h>
 #include <altq/altq_afmap.h>
 #include <altq/altq_blue.h>
@@ -87,7 +93,6 @@
 #include <sys/disk.h>
 #include <sys/disklabel.h>
 #include <sys/mount.h>
-#define RAY_DO_SIGLEV
 #include <dev/biovar.h>
 #include <dev/bluetooth/btdev.h>
 #include <dev/bluetooth/btsco.h>
@@ -204,6 +209,10 @@
 #include <utmpx.h>
 #include <wchar.h>
 #include <wordexp.h>
+#include <ttyent.h>
+
+#include <fts.h>
+#include <regex.h>
 
 // Include these after system headers to avoid name clashes and ambiguities.
 #include "sanitizer_internal_defs.h"
@@ -238,6 +247,10 @@ unsigned struct_rlimit_sz = sizeof(struc
 unsigned struct_timespec_sz = sizeof(struct timespec);
 unsigned struct_sembuf_sz = sizeof(struct sembuf);
 unsigned struct_kevent_sz = sizeof(struct kevent);
+unsigned struct_FTS_sz = sizeof(FTS);
+unsigned struct_FTSENT_sz = sizeof(FTSENT);
+unsigned struct_regex_sz = sizeof(regex_t);
+unsigned struct_regmatch_sz = sizeof(regmatch_t);
 unsigned struct_utimbuf_sz = sizeof(struct utimbuf);
 unsigned struct_itimerspec_sz = sizeof(struct itimerspec);
 unsigned struct_timex_sz = sizeof(struct timex);
