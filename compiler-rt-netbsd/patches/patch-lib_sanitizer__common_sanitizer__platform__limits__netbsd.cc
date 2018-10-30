$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2018-10-30 18:38:54.122499322 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -252,6 +252,10 @@ unsigned struct_rlimit_sz = sizeof(struc
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
@@ -364,7 +368,6 @@ unsigned struct_atabusiodetach_args_sz =
 unsigned struct_atabusioscan_args_sz = sizeof(atabusioscan_args);
 unsigned struct_ath_diag_sz = sizeof(ath_diag);
 unsigned struct_atm_flowmap_sz = sizeof(atm_flowmap);
-unsigned struct_atm_pseudoioctl_sz = sizeof(atm_pseudoioctl);
 unsigned struct_audio_buf_info_sz = sizeof(audio_buf_info);
 unsigned struct_audio_device_sz = sizeof(audio_device);
 unsigned struct_audio_encoding_sz = sizeof(audio_encoding);
@@ -610,7 +613,6 @@ unsigned struct_priq_delete_filter_sz = 
 unsigned struct_priq_interface_sz = sizeof(priq_interface);
 unsigned struct_priq_modify_class_sz = sizeof(priq_modify_class);
 unsigned struct_ptmget_sz = sizeof(ptmget);
-unsigned struct_pvctxreq_sz = sizeof(pvctxreq);
 unsigned struct_radio_info_sz = sizeof(radio_info);
 unsigned struct_red_conf_sz = sizeof(red_conf);
 unsigned struct_red_interface_sz = sizeof(red_interface);
@@ -1428,13 +1430,6 @@ unsigned IOCTL_BIOCSRTIMEOUT = BIOCSRTIM
 unsigned IOCTL_BIOCGRTIMEOUT = BIOCGRTIMEOUT;
 unsigned IOCTL_BIOCGFEEDBACK = BIOCGFEEDBACK;
 unsigned IOCTL_BIOCSFEEDBACK = BIOCSFEEDBACK;
-unsigned IOCTL_SIOCRAWATM = SIOCRAWATM;
-unsigned IOCTL_SIOCATMENA = SIOCATMENA;
-unsigned IOCTL_SIOCATMDIS = SIOCATMDIS;
-unsigned IOCTL_SIOCSPVCTX = SIOCSPVCTX;
-unsigned IOCTL_SIOCGPVCTX = SIOCGPVCTX;
-unsigned IOCTL_SIOCSPVCSIF = SIOCSPVCSIF;
-unsigned IOCTL_SIOCGPVCSIF = SIOCGPVCSIF;
 unsigned IOCTL_GRESADDRS = GRESADDRS;
 unsigned IOCTL_GRESADDRD = GRESADDRD;
 unsigned IOCTL_GREGADDRS = GREGADDRS;
@@ -1465,6 +1460,7 @@ unsigned IOCTL_PPPIOCGMTU = PPPIOCGMTU;
 unsigned IOCTL_PPPIOCSMTU = PPPIOCSMTU;
 unsigned IOCTL_SIOCGPPPSTATS = SIOCGPPPSTATS;
 unsigned IOCTL_SIOCGPPPCSTATS = SIOCGPPPCSTATS;
+#if 0
 unsigned IOCTL_IOC_NPF_VERSION = IOC_NPF_VERSION;
 unsigned IOCTL_IOC_NPF_SWITCH = IOC_NPF_SWITCH;
 unsigned IOCTL_IOC_NPF_LOAD = IOC_NPF_LOAD;
@@ -1473,6 +1469,7 @@ unsigned IOCTL_IOC_NPF_STATS = IOC_NPF_S
 unsigned IOCTL_IOC_NPF_SAVE = IOC_NPF_SAVE;
 unsigned IOCTL_IOC_NPF_RULE = IOC_NPF_RULE;
 unsigned IOCTL_IOC_NPF_CONN_LOOKUP = IOC_NPF_CONN_LOOKUP;
+#endif
 unsigned IOCTL_PPPOESETPARMS = PPPOESETPARMS;
 unsigned IOCTL_PPPOEGETPARMS = PPPOEGETPARMS;
 unsigned IOCTL_PPPOEGETSESSION = PPPOEGETSESSION;
@@ -1818,8 +1815,6 @@ unsigned IOCTL_MTIOCSLOCATE = MTIOCSLOCA
 unsigned IOCTL_MTIOCHLOCATE = MTIOCHLOCATE;
 unsigned IOCTL_POWER_EVENT_RECVDICT = POWER_EVENT_RECVDICT;
 unsigned IOCTL_POWER_IOC_GET_TYPE = POWER_IOC_GET_TYPE;
-unsigned IOCTL_POWER_IOC_GET_TYPE_WITH_LOSSAGE =
-    POWER_IOC_GET_TYPE_WITH_LOSSAGE;
 unsigned IOCTL_RIOCGINFO = RIOCGINFO;
 unsigned IOCTL_RIOCSINFO = RIOCSINFO;
 unsigned IOCTL_RIOCSSRCH = RIOCSSRCH;
@@ -2077,6 +2072,39 @@ unsigned IOCTL_SNDCTL_DSP_SILENCE = SNDC
 
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
@@ -2238,4 +2266,10 @@ CHECK_SIZE_AND_OFFSET(group, gr_passwd);
 CHECK_SIZE_AND_OFFSET(group, gr_gid);
 CHECK_SIZE_AND_OFFSET(group, gr_mem);
 
+CHECK_TYPE_SIZE(modctl_load_t);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_filename);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_flags);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_props);
+CHECK_SIZE_AND_OFFSET(modctl_load_t, ml_propslen);
+
 #endif  // SANITIZER_NETBSD
