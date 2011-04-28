$NetBSD: patch-net_base_dnsrr__resolver.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/base/dnsrr_resolver.cc.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/base/dnsrr_resolver.cc
@@ -4,6 +4,12 @@
 
 #include "net/base/dnsrr_resolver.h"
 
+#if defined(OS_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #if defined(OS_POSIX)
 #include <resolv.h>
 #endif
@@ -185,16 +191,18 @@ class RRResolverWorker {
     }
 
     bool r = true;
+#if !defined(OS_BSD)
     if ((_res.options & RES_INIT) == 0) {
       if (res_ninit(&_res) != 0)
         r = false;
     }
+#endif
 
     if (r) {
       unsigned long saved_options = _res.options;
       r = Do();
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
       if (!r && DnsReloadTimerHasExpired()) {
         // When there's no network connection, _res may not be initialized by
         // getaddrinfo. Therefore, we call res_nclose only when there are ns
