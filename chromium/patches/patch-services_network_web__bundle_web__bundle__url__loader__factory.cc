$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/web_bundle/web_bundle_url_loader_factory.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ services/network/web_bundle/web_bundle_url_loader_factory.cc
@@ -586,6 +586,7 @@ bool WebBundleURLLoaderFactory::HasError
 
 void WebBundleURLLoaderFactory::SetBundleStream(
     mojo::ScopedDataPipeConsumerHandle body) {
+#if !BUILDFLAG(IS_BSD)
   if (HasError())
     return;
   mojo::PendingRemote<web_package::mojom::BundleDataSource> data_source;
@@ -605,6 +606,11 @@ void WebBundleURLLoaderFactory::SetBundl
       /*offset=*/std::nullopt,
       base::BindOnce(&WebBundleURLLoaderFactory::OnMetadataParsed,
                      weak_ptr_factory_.GetWeakPtr()));
+#else
+  // XXX crubit
+  NOTIMPLEMENTED();
+  return;
+#endif
 }
 
 mojo::PendingRemote<mojom::URLLoaderClient>
