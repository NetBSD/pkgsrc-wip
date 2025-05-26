$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/search_engines/template_url_service.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/search_engines/template_url_service.cc
@@ -3062,7 +3062,7 @@ bool TemplateURLService::MatchesDefaultS
 std::unique_ptr<EnterpriseSearchManager>
 TemplateURLService::GetEnterpriseSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<EnterpriseSearchManager>(
       prefs,
       base::BindRepeating(&TemplateURLService::EnterpriseSiteSearchChanged,
