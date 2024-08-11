$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/http/http_auth_handler_negotiate.cc.orig	2024-07-24 02:44:42.613360400 +0000
+++ net/http/http_auth_handler_negotiate.cc
@@ -120,7 +120,7 @@ int HttpAuthHandlerNegotiate::Factory::C
 #elif BUILDFLAG(IS_POSIX)
   if (is_unsupported_)
     return ERR_UNSUPPORTED_AUTH_SCHEME;
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Note: Don't set is_unsupported_ = true here. AllowGssapiLibraryLoad()
   // might change to true during a session.
   if (!http_auth_preferences() ||
