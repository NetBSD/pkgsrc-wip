$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/session_policies_from_dict.cc.orig	2025-02-17 21:09:38.000000000 +0000
+++ remoting/host/session_policies_from_dict.cc
@@ -76,7 +76,7 @@ std::optional<SessionPolicies> SessionPo
       .curtain_required =
           dict.FindBool(policy::key::kRemoteAccessHostRequireCurtain),
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       .host_username_match_required =
           dict.FindBool(policy::key::kRemoteAccessHostMatchUsername),
 #endif
