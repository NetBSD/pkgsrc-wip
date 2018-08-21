$NetBSD$

--- lib/sanitizer_common/sanitizer_interceptors_ioctl_netbsd.inc.orig	2018-08-21 21:25:40.000000000 +0000
+++ lib/sanitizer_common/sanitizer_interceptors_ioctl_netbsd.inc
@@ -1095,7 +1095,6 @@ static void ioctl_table_fill() {
   /* Entries from file: sys/power.h */
   _(POWER_EVENT_RECVDICT, READWRITE, struct_plistref_sz);
   _(POWER_IOC_GET_TYPE, WRITE, struct_power_type_sz);
-  _(POWER_IOC_GET_TYPE_WITH_LOSSAGE, WRITE, sizeof(uptr));
   /* Entries from file: sys/radioio.h */
   _(RIOCGINFO, WRITE, struct_radio_info_sz);
   _(RIOCSINFO, READWRITE, struct_radio_info_sz);
