$NetBSD$

--- net/cert/cert_verify_proc.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ net/cert/cert_verify_proc.cc
@@ -494,7 +494,7 @@ base::Value CertVerifyParams(X509Certifi
 
 }  // namespace
 
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 // static
 scoped_refptr<CertVerifyProc> CertVerifyProc::CreateSystemVerifyProc(
     scoped_refptr<CertNetFetcher> cert_net_fetcher) {
