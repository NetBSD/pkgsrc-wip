$NetBSD: patch-security_manager_ssl_src_nsNSSComponent.cpp,v 1.1 2014/09/29 10:46:25 thomasklausner Exp $

--- security/manager/ssl/src/nsNSSComponent.cpp.orig	2014-09-28 08:30:06.000000000 +0000
+++ security/manager/ssl/src/nsNSSComponent.cpp
@@ -44,6 +44,7 @@
 #include "nss.h"
 #include "pkix/pkixnss.h"
 #include "ssl.h"
+#define NSS_ENABLE_ECC 1
 #include "sslproto.h"
 #include "secmod.h"
 #include "secerr.h"
