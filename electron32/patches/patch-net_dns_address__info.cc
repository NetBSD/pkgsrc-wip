$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/dns/address_info.cc.orig	2024-10-18 12:34:30.266578400 +0000
+++ net/dns/address_info.cc
@@ -83,8 +83,12 @@ AddressInfo::AddressInfoAndResult Addres
     // error.
     // http://crbug.com/134142
     err = ERR_NAME_NOT_RESOLVED;
-#elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_FREEBSD)
+#elif BUILDFLAG(IS_POSIX)
+#ifdef EAI_NODATA
     if (os_error != EAI_NONAME && os_error != EAI_NODATA)
+#else
+    if (os_error != EAI_NONAME)
+#endif
       err = ERR_NAME_RESOLUTION_FAILED;
 #endif
 
