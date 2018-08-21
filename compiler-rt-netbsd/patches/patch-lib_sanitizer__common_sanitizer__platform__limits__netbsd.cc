$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2018-08-21 21:25:40.000000000 +0000
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
@@ -134,10 +142,12 @@
 #include <netinet6/nd6.h>
 #include <netnatm/natm.h>
 #include <netsmb/smb_dev.h>
+#include <rmd160.h>
 #include <soundcard.h>
 #include <sys/agpio.h>
 #include <sys/ataio.h>
 #include <sys/audioio.h>
+#include <sys/cdbr.h>
 #include <sys/cdio.h>
 #include <sys/chio.h>
 #include <sys/clockctl.h>
@@ -173,6 +183,7 @@
 #include <sys/filio.h>
 #include <sys/ipc.h>
 #include <sys/mman.h>
+#include <sys/module.h>
 #include <sys/mount.h>
 #include <sys/mqueue.h>
 #include <sys/msg.h>
@@ -180,6 +191,8 @@
 #include <sys/ptrace.h>
 #include <sys/resource.h>
 #include <sys/sem.h>
+#include <sys/sha1.h>
+#include <sys/sha2.h>
 #include <sys/shm.h>
 #include <sys/signal.h>
 #include <sys/socket.h>
@@ -202,8 +215,13 @@
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
@@ -238,6 +256,10 @@ unsigned struct_rlimit_sz = sizeof(struc
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
@@ -1804,8 +1826,6 @@ unsigned IOCTL_MTIOCSLOCATE = MTIOCSLOCA
 unsigned IOCTL_MTIOCHLOCATE = MTIOCHLOCATE;
 unsigned IOCTL_POWER_EVENT_RECVDICT = POWER_EVENT_RECVDICT;
 unsigned IOCTL_POWER_IOC_GET_TYPE = POWER_IOC_GET_TYPE;
-unsigned IOCTL_POWER_IOC_GET_TYPE_WITH_LOSSAGE =
-    POWER_IOC_GET_TYPE_WITH_LOSSAGE;
 unsigned IOCTL_RIOCGINFO = RIOCGINFO;
 unsigned IOCTL_RIOCSINFO = RIOCSINFO;
 unsigned IOCTL_RIOCSSRCH = RIOCSSRCH;
@@ -2063,6 +2083,39 @@ unsigned IOCTL_SNDCTL_DSP_SILENCE = SNDC
 
 const int si_SEGV_MAPERR = SEGV_MAPERR;
 const int si_SEGV_ACCERR = SEGV_ACCERR;
+
+const unsigned SHA1_CTX_sz = sizeof(SHA1_CTX);
+const unsigned SHA1_return_length = SHA1_DIGEST_STRING_LENGTH; // 41
+const unsigned MD2_CTX_sz = sizeof(MD2_CTX);
+const unsigned MD2_return_length = MD2_DIGEST_STRING_LENGTH; // 33
+const unsigned MD4_CTX_sz = sizeof(MD4_CTX);
+const unsigned MD4_return_length = 33;
+const unsigned MD5_CTX_sz = sizeof(MD5_CTX);
+const unsigned MD5_return_length = MD5_DIGEST_STRING_LENGTH; // 33
+const unsigned RMD160_CTX_sz = sizeof(RMD160_CTX);
+const unsigned RMD160_return_length = RMD160_DIGEST_STRING_LENGTH;// 41
+
+#define SHA2_CONST(LEN) \
+  const unsigned SHA##LEN##_CTX_sz = sizeof(SHA##LEN##_CTX); \
+  const unsigned SHA##LEN##_return_length = SHA##LEN##_DIGEST_STRING_LENGTH; \
+  const unsigned SHA##LEN##_block_length = SHA##LEN##_BLOCK_LENGTH; \
+  const unsigned SHA##LEN##_digest_length = SHA##LEN##_DIGEST_LENGTH
+
+SHA2_CONST(224);
+SHA2_CONST(256);
+SHA2_CONST(384);
+SHA2_CONST(512);
+
+#undef SHA2_CONST
+
+const int unvis_valid = UNVIS_VALID;
+const int unvis_validpush = UNVIS_VALIDPUSH;
+const int modctl_load = MODCTL_LOAD;
+const int modctl_unload = MODCTL_UNLOAD;
+const int modctl_stat = MODCTL_STAT;
+const int modctl_exists = MODCTL_EXISTS;
+const unsigned fpos_t_sz = sizeof(fpos_t);
+const int setvbuf_bufsiz = BUFSIZ;
 }  // namespace __sanitizer
 
 using namespace __sanitizer;
@@ -2224,4 +2277,10 @@ CHECK_SIZE_AND_OFFSET(group, gr_passwd);
 CHECK_SIZE_AND_OFFSET(group, gr_gid);
 CHECK_SIZE_AND_OFFSET(group, gr_mem);
 
+CHECK_TYPE_SIZE(modctl_load_t);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_filename);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_flags);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_props);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_propslen);
+
 #endif  // SANITIZER_NETBSD
