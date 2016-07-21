$NetBSD$

--- net/dns/host_resolver_impl.cc.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/dns/host_resolver_impl.cc
@@ -1888,7 +1888,7 @@ HostResolverImpl::HostResolverImpl(const
   NetworkChangeNotifier::AddConnectionTypeObserver(this);
   NetworkChangeNotifier::AddDNSObserver(this);
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
-    !defined(OS_ANDROID)
+    !defined(OS_ANDROID) && !defined(OS_NETBSD)
   EnsureDnsReloaderInit();
 #endif
 
