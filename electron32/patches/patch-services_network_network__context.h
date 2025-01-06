$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/network_context.h.orig	2024-10-18 12:34:32.073729000 +0000
+++ services/network/network_context.h
@@ -115,6 +115,7 @@ class URLMatcher;
 }
 
 namespace network {
+class RemoteCertVerifier;
 class CookieManager;
 class HostResolver;
 class MdnsResponderManager;
@@ -246,6 +247,8 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
   void CreateURLLoaderFactory(
       mojo::PendingReceiver<mojom::URLLoaderFactory> receiver,
       mojom::URLLoaderFactoryParamsPtr params) override;
+  void SetCertVerifierClient(
+      mojo::PendingRemote<mojom::CertVerifierClient> client) override;
   void ResetURLLoaderFactories() override;
   void GetViaObliviousHttp(
       mojom::ObliviousHttpRequestPtr request,
@@ -312,6 +315,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
   void CloseIdleConnections(CloseIdleConnectionsCallback callback) override;
   void SetNetworkConditions(const base::UnguessableToken& throttling_profile_id,
                             mojom::NetworkConditionsPtr conditions) override;
+  void SetUserAgent(const std::string& new_user_agent) override;
   void SetAcceptLanguage(const std::string& new_accept_language) override;
   void SetEnableReferrers(bool enable_referrers) override;
 #if BUILDFLAG(IS_CT_SUPPORTED)
@@ -692,7 +696,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:
@@ -921,6 +925,8 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
   std::vector<base::OnceClosure> dismount_closures_;
 #endif  // BUILDFLAG(IS_DIRECTORY_TRANSFER_REQUIRED)
 
+  raw_ptr<RemoteCertVerifier> remote_cert_verifier_ = nullptr;
+
   // Created on-demand. Null if unused.
   std::unique_ptr<HostResolver> internal_host_resolver_;
   std::set<std::unique_ptr<HostResolver>, base::UniquePtrComparator>
