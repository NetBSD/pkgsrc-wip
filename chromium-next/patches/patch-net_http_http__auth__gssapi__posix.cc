$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/http/http_auth_gssapi_posix.cc.orig	2025-03-20 19:11:33.000000000 +0000
+++ net/http/http_auth_gssapi_posix.cc
@@ -375,8 +375,9 @@ base::NativeLibrary GSSAPISharedLibrary:
     static const char* const kDefaultLibraryNames[] = {
 #if BUILDFLAG(IS_APPLE)
       "/System/Library/Frameworks/GSS.framework/GSS"
-#elif BUILDFLAG(IS_OPENBSD)
-      "libgssapi.so"  // Heimdal - OpenBSD
+#elif BUILDFLAG(IS_BSD)
+      "libgssapi_krb5.so.2",  // MIT Kerberos - FreeBSD
+      "libgssapi.so"          // Heimdal - OpenBSD, FreeBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
