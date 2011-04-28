$NetBSD: patch-net_base_host__resolver__impl.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/base/host_resolver_impl.cc.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/base/host_resolver_impl.cc
@@ -199,13 +199,11 @@ class JobCreationParameters : public Net
 std::vector<int> GetAllGetAddrinfoOSErrors() {
   int os_errors[] = {
 #if defined(OS_POSIX)
-    EAI_ADDRFAMILY,
     EAI_AGAIN,
     EAI_BADFLAGS,
     EAI_FAIL,
     EAI_FAMILY,
     EAI_MEMORY,
-    EAI_NODATA,
     EAI_NONAME,
     EAI_SERVICE,
     EAI_SOCKTYPE,
@@ -919,7 +917,7 @@ HostResolverImpl::HostResolverImpl(
 #if defined(OS_WIN)
   EnsureWinsockInit();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (HaveOnlyLoopbackAddresses())
     additional_resolver_flags_ |= HOST_RESOLVER_LOOPBACK_ONLY;
 #endif
@@ -1447,7 +1445,7 @@ void HostResolverImpl::OnIPAddressChange
     ipv6_probe_job_ = new IPv6ProbeJob(this);
     ipv6_probe_job_->Start();
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (HaveOnlyLoopbackAddresses()) {
     additional_resolver_flags_ |= HOST_RESOLVER_LOOPBACK_ONLY;
   } else {
