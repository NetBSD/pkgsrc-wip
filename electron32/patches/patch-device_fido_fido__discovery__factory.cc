$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- device/fido/fido_discovery_factory.cc.orig	2024-10-18 12:34:16.657237000 +0000
+++ device/fido/fido_discovery_factory.cc
@@ -127,7 +127,7 @@ std::vector<std::unique_ptr<FidoDiscover
 
 std::optional<std::unique_ptr<FidoDiscoveryBase>>
 FidoDiscoveryFactory::MaybeCreateEnclaveDiscovery() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kWebAuthnEnclaveAuthenticator) ||
       !enclave_ui_request_stream_ || !network_context_factory_) {
     return std::nullopt;
