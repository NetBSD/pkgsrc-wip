$NetBSD$

--- net/dns/dns_reloader.cc.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/dns/dns_reloader.cc
@@ -7,6 +7,10 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID)
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
+
 #include <resolv.h>
 
 #include "base/lazy_instance.h"
@@ -21,6 +25,8 @@ namespace net {
 
 namespace {
 
+struct __res_state res;
+
 // On Linux/BSD, changes to /etc/resolv.conf can go unnoticed thus resulting
 // in DNS queries failing either because nameservers are unknown on startup
 // or because nameserver info has changed as a result of e.g. connecting to
@@ -61,14 +67,14 @@ class DnsReloader : public NetworkChange
     if (!reload_state) {
       reload_state = new ReloadState();
       reload_state->resolver_generation = resolver_generation_;
-      res_ninit(&_res);
+      res_ninit(&res);
       tls_index_.Set(reload_state);
     } else if (reload_state->resolver_generation != resolver_generation_) {
       reload_state->resolver_generation = resolver_generation_;
       // It is safe to call res_nclose here since we know res_ninit will have
       // been called above.
-      res_nclose(&_res);
-      res_ninit(&_res);
+      res_nclose(&res);
+      res_ninit(&res);
     }
   }
 
@@ -76,7 +82,7 @@ class DnsReloader : public NetworkChange
   static void SlotReturnFunction(void* data) {
     ReloadState* reload_state = static_cast<ReloadState*>(data);
     if (reload_state)
-      res_nclose(&_res);
+      res_nclose(&res);
     delete reload_state;
   }
 
