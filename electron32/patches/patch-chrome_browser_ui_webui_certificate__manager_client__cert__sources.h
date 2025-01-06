$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2024-10-18 12:34:03.652108400 +0000
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -15,7 +15,7 @@ class Profile;
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreatePlatformClientCertSource();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
