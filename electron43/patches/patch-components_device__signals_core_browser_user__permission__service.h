$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/device_signals/core/browser/user_permission_service.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/device_signals/core/browser/user_permission_service.h
@@ -57,7 +57,7 @@ class UserPermissionService : public Key
   // missing.
   virtual bool ShouldCollectConsent() const = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Will verify whether context-aware signals can be collected
   // on behalf of the user represented by `user_context`. Returns `kGranted` if
   // collection is allowed.
