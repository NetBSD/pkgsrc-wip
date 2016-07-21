$NetBSD$

--- net/dns/host_resolver_proc.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/dns/host_resolver_proc.cc
@@ -194,7 +194,7 @@ int SystemHostResolverCall(const std::st
   hints.ai_socktype = SOCK_STREAM;
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
-    !defined(OS_ANDROID)
+    !defined(OS_ANDROID) && !defined(OS_NETBSD)
   DnsReloaderMaybeReload();
 #endif
   int err = getaddrinfo(host.c_str(), NULL, &hints, &ai);
