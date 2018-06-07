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
@@ -115,6 +120,9 @@
 #include <dev/vndvar.h>
 #include <dev/wscons/wsconsio.h>
 #include <dev/wscons/wsdisplay_usl_io.h>
+#include <md2.h>
+#include <md4.h>
+#include <md5.h>
 #include <net/bpf.h>
 #include <net/if_atm.h>
 #include <net/if_gre.h>
@@ -173,6 +181,7 @@
 #include <sys/filio.h>
 #include <sys/ipc.h>
 #include <sys/mman.h>
+#include <sys/module.h>
 #include <sys/mount.h>
 #include <sys/mqueue.h>
 #include <sys/msg.h>
@@ -180,6 +189,7 @@
 #include <sys/ptrace.h>
 #include <sys/resource.h>
 #include <sys/sem.h>
+#include <sys/sha1.h>
 #include <sys/shm.h>
 #include <sys/signal.h>
 #include <sys/socket.h>
@@ -202,8 +212,13 @@
 #include <utime.h>
 #include <utmp.h>
 #include <utmpx.h>
+#include <vis.h>
 #include <wchar.h>
 #include <wordexp.h>
+#include <ttyent.h>
+
+#include <fts.h>
+#include <regex.h>
 
 // Include these after system headers to avoid name clashes and ambiguities.
 #include "sanitizer_internal_defs.h"
@@ -238,6 +253,10 @@ unsigned struct_rlimit_sz = sizeof(struc
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
@@ -2063,6 +2082,21 @@ unsigned IOCTL_SNDCTL_DSP_SILENCE = SNDC
 
 const int si_SEGV_MAPERR = SEGV_MAPERR;
 const int si_SEGV_ACCERR = SEGV_ACCERR;
+
+unsigned SHA1_CTX_sz = sizeof(SHA1_CTX);
+unsigned SHA1_return_length = 41;
+unsigned MD2_CTX_sz = sizeof(MD2_CTX);
+unsigned MD2_return_length = 33;
+unsigned MD4_CTX_sz = sizeof(MD4_CTX);
+unsigned MD4_return_length = 33;
+unsigned MD5_CTX_sz = sizeof(MD5_CTX);
+unsigned MD5_return_length = 33;
+int unvis_valid = UNVIS_VALID;
+int unvis_validpush = UNVIS_VALIDPUSH;
+int modctl_load = MODCTL_LOAD;
+int modctl_unload = MODCTL_UNLOAD;
+int modctl_stat = MODCTL_STAT;
+int modctl_exists = MODCTL_EXISTS;
 }  // namespace __sanitizer
 
 using namespace __sanitizer;
