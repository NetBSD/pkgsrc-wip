$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -19,7 +19,7 @@ CreatePlatformClientCertSource(
         remote_client,
     Profile* profile);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
@@ -29,7 +29,7 @@ std::unique_ptr<CertificateManagerPageHa
 CreateExtensionsClientCertSource(Profile* profile);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ClientCertManagementAccessControls {
  public:
   enum KeyStorage {
