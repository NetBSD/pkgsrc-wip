$NetBSD: patch-dom_webtransport_api_WebTransportDatagramDuplexStream.cpp,v 1.1 2023/06/04 09:26:35 ryoon Exp $

--- dom/webtransport/api/WebTransportDatagramDuplexStream.cpp.orig	2026-11-18 05:48:11.000000000 +0000
+++ dom/webtransport/api/WebTransportDatagramDuplexStream.cpp
@@ -88,7 +88,7 @@ void WebTransportDatagramDuplexStream::SetIncomingMaxA
   Nullable<double> value = aMaxAge;
   if (!value.IsNull()) {
     // Step 1
-    if (isnan(value.Value()) || value.Value() < 0.) {
+    if (std::isnan(value.Value()) || value.Value() < 0.) {
       aRv.ThrowRangeError("Invalid IncomingMaxAge");
       return;
     }
@@ -107,7 +107,7 @@ void WebTransportDatagramDuplexStream::SetOutgoingMaxA
   Nullable<double> value = aMaxAge;
   if (!value.IsNull()) {
     // Step 1
-    if (isnan(value.Value()) || value.Value() < 0.) {
+    if (std::isnan(value.Value()) || value.Value() < 0.) {
       aRv.ThrowRangeError("Invalid OutgoingMaxAge");
       return;
     }
