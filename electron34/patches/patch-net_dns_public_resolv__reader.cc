$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/dns/public/resolv_reader.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ net/dns/public/resolv_reader.cc
@@ -40,7 +40,7 @@ std::optional<std::vector<IPEndPoint>> G
   if (!(res.options & RES_INIT))
     return std::nullopt;
 
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   union res_sockaddr_union addresses[MAXNS];
   int nscount = res_getservers(const_cast<res_state>(&res), addresses, MAXNS);
   DCHECK_GE(nscount, 0);
