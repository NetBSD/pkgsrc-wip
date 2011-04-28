$NetBSD: patch-net_base_host__resolver__proc.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/base/host_resolver_proc.cc.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/base/host_resolver_proc.cc
@@ -6,6 +6,12 @@
 
 #include "build/build_config.h"
 
+#if defined(OS_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #if defined(OS_POSIX) && !defined(OS_MACOSX)
 #include <resolv.h>
 #endif
@@ -156,7 +162,7 @@ int SystemHostResolverProc(const std::st
       hints.ai_family = AF_UNSPEC;
   }
 
-#if defined(OS_WIN) || defined(OS_OPENBSD)
+#if defined(OS_WIN) || defined(OS_OPENBSD) || defined(OS_NETBSD)
   // DO NOT USE AI_ADDRCONFIG ON WINDOWS.
   //
   // The following comment in <winsock2.h> is the best documentation I found
@@ -180,6 +186,7 @@ int SystemHostResolverProc(const std::st
   //
   // OpenBSD does not support it, either.
   hints.ai_flags = 0;
+#define AI_ADDRCONFIG 0
 #else
   hints.ai_flags = AI_ADDRCONFIG;
 #endif
@@ -198,7 +205,8 @@ int SystemHostResolverProc(const std::st
 
   int err = getaddrinfo(host.c_str(), NULL, &hints, &ai);
   bool should_retry = false;
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
+    !defined(OS_NETBSD)
   // If we fail, re-initialise the resolver just in case there have been any
   // changes to /etc/resolv.conf and retry. See http://crbug.com/11380 for info.
   if (err && DnsReloadTimerHasExpired()) {
