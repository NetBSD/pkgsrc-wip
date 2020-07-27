$NetBSD$

--- net/http/http_auth_gssapi_posix.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ net/http/http_auth_gssapi_posix.cc
@@ -367,8 +367,9 @@ base::NativeLibrary GSSAPISharedLibrary:
     static const char* const kDefaultLibraryNames[] = {
 #if defined(OS_MACOSX)
       "/System/Library/Frameworks/GSS.framework/GSS"
-#elif defined(OS_OPENBSD)
-      "libgssapi.so"          // Heimdal - OpenBSD
+#elif defined(OS_BSD)
+      "libgssapi_krb5.so"     // MIT Kerberos - FreeBSD
+      "libgssapi.so"          // Heimdal - OpenBSD/NetBSD
 #else
       "libgssapi_krb5.so.2",  // MIT Kerberos - FC, Suse10, Debian
       "libgssapi.so.4",       // Heimdal - Suse10, MDK
