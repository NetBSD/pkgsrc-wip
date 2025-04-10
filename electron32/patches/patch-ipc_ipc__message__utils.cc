$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ipc/ipc_message_utils.cc.orig	2024-10-18 12:34:27.479903000 +0000
+++ ipc/ipc_message_utils.cc
@@ -400,7 +400,7 @@ void ParamTraits<unsigned int>::Log(cons
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) ||                                              \
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) ||                         \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
