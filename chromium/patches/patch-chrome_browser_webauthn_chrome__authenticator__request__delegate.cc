$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2024-09-24 20:49:21.268228800 +0000
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -1167,7 +1167,7 @@ void ChromeAuthenticatorRequestDelegate:
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
