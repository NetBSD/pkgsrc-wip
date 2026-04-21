$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -543,7 +543,7 @@ void ChromeAuthenticatorRequestDelegate:
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (std::ranges::contains(pairings_from_extension,
                             device::CableDiscoveryData::Version::V1,
