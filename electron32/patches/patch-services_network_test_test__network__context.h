$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/test/test_network_context.h.orig	2024-10-18 12:34:32.109712400 +0000
+++ services/network/test/test_network_context.h
@@ -63,6 +63,8 @@ class TestNetworkContext : public mojom:
   void CreateURLLoaderFactory(
       mojo::PendingReceiver<mojom::URLLoaderFactory> receiver,
       mojom::URLLoaderFactoryParamsPtr params) override {}
+  void SetCertVerifierClient(
+      mojo::PendingRemote<mojom::CertVerifierClient> client) override {}
   void GetCookieManager(
       mojo::PendingReceiver<mojom::CookieManager> cookie_manager) override {}
   void GetRestrictedCookieManager(
@@ -149,6 +151,7 @@ class TestNetworkContext : public mojom:
   void CloseIdleConnections(CloseIdleConnectionsCallback callback) override {}
   void SetNetworkConditions(const base::UnguessableToken& throttling_profile_id,
                             mojom::NetworkConditionsPtr conditions) override {}
+  void SetUserAgent(const std::string& new_user_agent) override {}
   void SetAcceptLanguage(const std::string& new_accept_language) override {}
   void SetEnableReferrers(bool enable_referrers) override {}
 #if BUILDFLAG(IS_CT_SUPPORTED)
