$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/network_service.cc.orig	2024-10-18 12:34:32.077727000 +0000
+++ services/network/network_service.cc
@@ -99,7 +99,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
+#if ((BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #include "components/os_crypt/sync/key_storage_config_linux.h"
@@ -975,7 +975,7 @@ void NetworkService::SetExplicitlyAllowe
   net::SetExplicitlyAllowedPorts(ports);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::SetGssapiLibraryLoadObserver(
     mojo::PendingRemote<mojom::GssapiLibraryLoadObserver>
         gssapi_library_load_observer) {
@@ -1057,7 +1057,7 @@ NetworkService::CreateHttpAuthHandlerFac
   );
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::OnBeforeGssapiLibraryLoad() {
   if (gssapi_library_load_observer_.is_bound()) {
     gssapi_library_load_observer_->OnBeforeGssapiLibraryLoad();
