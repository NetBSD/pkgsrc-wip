$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/loader/document_loader.cc.orig	2024-10-18 12:34:35.544119800 +0000
+++ third_party/blink/renderer/core/loader/document_loader.cc
@@ -2243,6 +2243,10 @@ Frame* DocumentLoader::CalculateOwnerFra
 scoped_refptr<SecurityOrigin> DocumentLoader::CalculateOrigin(
     Document* owner_document) {
   scoped_refptr<SecurityOrigin> origin;
+  bool is_standard = false;
+  std::string protocol = url_.Protocol().Ascii();
+  is_standard = url::IsStandard(
+      protocol.data(), url::Component(0, static_cast<int>(protocol.size())));
   StringBuilder debug_info_builder;
   // Whether the origin is newly created within this call, instead of copied
   // from an existing document's origin or from `origin_to_commit_`. If this is
@@ -2295,6 +2299,10 @@ scoped_refptr<SecurityOrigin> DocumentLo
     debug_info_builder.Append(", url=");
     debug_info_builder.Append(owner_document->Url().BaseAsString());
     debug_info_builder.Append(")");
+  } else if (!SecurityOrigin::ShouldUseInnerURL(url_) &&
+             !is_standard) {
+    debug_info_builder.Append("use_url_with_non_standard_scheme");
+    origin = SecurityOrigin::Create(url_);
   } else {
     debug_info_builder.Append("use_url_with_precursor");
     // Otherwise, create an origin that propagates precursor information
