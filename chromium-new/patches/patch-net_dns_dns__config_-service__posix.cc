$NetBSD$

--- net/dns/dns_config_service_posix.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/dns/dns_config_service_posix.cc
@@ -118,7 +118,7 @@ class DnsConfigWatcher {
 ConfigParsePosixResult ReadDnsConfig(DnsConfig* config) {
   ConfigParsePosixResult result;
   config->unhandled_options = false;
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
   // Note: res_ninit in glibc always returns 0 and sets RES_INIT.
   // res_init behaves the same way.
   memset(&_res, 0, sizeof(_res));
