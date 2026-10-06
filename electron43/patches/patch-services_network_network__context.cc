$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/network_context.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ services/network/network_context.cc
@@ -158,6 +158,11 @@
 #include "services/network/web_transport.h"
 #include "url/gurl.h"
 
+// Electron
+#include "net/cert/caching_cert_verifier.h"
+#include "net/cert/cert_verify_proc.h"
+#include "net/cert/multi_threaded_cert_verifier.h"
+
 #if BUILDFLAG(IS_CT_SUPPORTED)
 // gn check does not account for BUILDFLAG(). So, for iOS builds, it will
 // complain about a missing dependency on the target exposing this header. Add a
@@ -606,6 +611,99 @@ void RecordHSTSPreconnectUpgradeReason(H
 
 }  // namespace
 
+class RemoteCertVerifier : public net::CertVerifier {
+ public:
+  class Request : public net::CertVerifier::Request {
+   public:
+    Request() {}
+    ~Request() override = default;
+    void OnRemoteResponse(
+        const RequestParams& params,
+        net::CertVerifyResult* verify_result,
+        int error_from_upstream,
+        net::CompletionOnceCallback callback,
+        int error_from_client,
+        const net::CertVerifyResult& verify_result_from_client) {
+      if (error_from_client == net::ERR_ABORTED) {
+        // use the default
+        std::move(callback).Run(error_from_upstream);
+      } else {
+        // use the override
+        verify_result->Reset();
+        verify_result->verified_cert = verify_result_from_client.verified_cert;
+        std::move(callback).Run(error_from_client);
+      }
+    }
+    base::WeakPtr<Request> GetWeakPtr() { return weak_factory_.GetWeakPtr(); }
+   private:
+    base::WeakPtrFactory<Request> weak_factory_{this};
+  };
+
+  RemoteCertVerifier(std::unique_ptr<net::CertVerifier> upstream): upstream_(std::move(upstream)) {
+  }
+  ~RemoteCertVerifier() override = default;
+
+  void Bind(
+      mojo::PendingRemote<mojom::CertVerifierClient> client_info) {
+    client_.reset();
+    if (client_info.is_valid()) {
+      client_.Bind(std::move(client_info));
+    }
+  }
+
+  // CertVerifier implementation
+  int Verify(const RequestParams& params,
+             net::CertVerifyResult* verify_result,
+             net::CompletionOnceCallback callback,
+             std::unique_ptr<CertVerifier::Request>* out_req,
+             const net::NetLogWithSource& net_log) override {
+    out_req->reset();
+
+    net::CompletionOnceCallback callback2 = base::BindOnce(
+        &RemoteCertVerifier::OnRequestFinished, base::Unretained(this),
+        params, std::move(callback), verify_result, out_req);
+    return upstream_->Verify(params, verify_result, std::move(callback2), out_req, net_log);
+  }
+
+
+  void SetConfig(const Config& config) override {
+    upstream_->SetConfig(config);
+  }
+
+  void AddObserver(CertVerifier::Observer* observer) override {
+    upstream_->AddObserver(observer);
+  }
+
+  void RemoveObserver(CertVerifier::Observer* observer) override {
+    upstream_->RemoveObserver(observer);
+  }
+
+  void OnRequestFinished(const RequestParams& params,
+                         net::CompletionOnceCallback callback,
+                         net::CertVerifyResult* verify_result,
+                         std::unique_ptr<CertVerifier::Request>* out_req,
+                         int error) {
+    if (client_.is_bound()) {
+      // We take a weak pointer to the request because deletion of the request
+      // is what signals cancellation. Thus if the request is cancelled, the
+      // callback won't be called, thus avoiding UAF, because |verify_result|
+      // is freed when the request is cancelled.
+      *out_req = std::make_unique<Request>();
+      base::WeakPtr<Request> weak_req = static_cast<Request*>(out_req->get())->GetWeakPtr();
+      client_->Verify(error, *verify_result, params.certificate(),
+          params.hostname(), params.flags(), params.ocsp_response(),
+          base::BindOnce(&Request::OnRemoteResponse,
+            weak_req, params, verify_result, error, std::move(callback)));
+    } else {
+      std::move(callback).Run(error);
+    }
+  }
+
+ private:
+  std::unique_ptr<net::CertVerifier> upstream_;
+  mojo::Remote<mojom::CertVerifierClient> client_;
+};
+
 constexpr uint32_t NetworkContext::kMaxOutstandingRequestsPerProcess;
 
 NetworkContext::NetworkContextHttpAuthPreferences::
@@ -615,7 +713,7 @@ NetworkContext::NetworkContextHttpAuthPr
 NetworkContext::NetworkContextHttpAuthPreferences::
     ~NetworkContextHttpAuthPreferences() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool NetworkContext::NetworkContextHttpAuthPreferences::AllowGssapiLibraryLoad()
     const {
   if (network_service_) {
@@ -1003,6 +1101,13 @@ void NetworkContext::SetClient(
   client_.Bind(std::move(client));
 }
 
+void NetworkContext::SetCertVerifierClient(
+    mojo::PendingRemote<mojom::CertVerifierClient> client) {
+  if (remote_cert_verifier_) {
+    remote_cert_verifier_->Bind(std::move(client));
+  }
+}
+
 void NetworkContext::CreateURLLoaderFactory(
     mojo::PendingReceiver<mojom::URLLoaderFactory> receiver,
     mojom::URLLoaderFactoryParamsPtr params) {
@@ -1691,6 +1796,13 @@ void NetworkContext::SetNetworkCondition
                                       std::move(network_conditions));
 }
 
+void NetworkContext::SetUserAgent(const std::string& new_user_agent) {
+  // This may only be called on NetworkContexts created with a constructor that
+  // calls ApplyContextParamsToBuilder.
+  DCHECK(user_agent_settings_);
+  user_agent_settings_->set_user_agent(new_user_agent);
+}
+
 void NetworkContext::SetAcceptLanguage(const std::string& new_accept_language) {
   // This may only be called on NetworkContexts created with the constructor
   // that calls MakeURLRequestContext().
@@ -2499,7 +2611,7 @@ void NetworkContext::OnHttpAuthDynamicPa
       http_auth_dynamic_network_service_params->android_negotiate_account_type);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   http_auth_merged_preferences_.set_allow_gssapi_library_load(
       http_auth_dynamic_network_service_params->allow_gssapi_library_load);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -2572,6 +2684,9 @@ URLRequestContextOwner NetworkContext::M
         std::move(cert_verifier));
     cert_verifier = std::move(cert_verifier_with_trust_anchors);
 #endif  // BUILDFLAG(IS_CHROMEOS)
+    auto remote_cert_verifier = std::make_unique<RemoteCertVerifier>(std::move(cert_verifier));
+    remote_cert_verifier_ = remote_cert_verifier.get();
+    cert_verifier = std::make_unique<net::CachingCertVerifier>(std::move(remote_cert_verifier));
   }
 
   builder.SetCertVerifier(IgnoreErrorsCertVerifier::MaybeWrapCertVerifier(
