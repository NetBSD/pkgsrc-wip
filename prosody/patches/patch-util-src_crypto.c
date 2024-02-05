$NetBSD$

ec.h is needed to find the required EC_ definitions 

--- util-src/crypto.c.orig	2024-02-04 21:10:41.303639710 +0000
+++ util-src/crypto.c
@@ -24,6 +24,7 @@ typedef unsigned __int32 uint32_t;
 #include "lauxlib.h"
 #include <openssl/crypto.h>
 #include <openssl/ecdsa.h>
+#include <openssl/ec.h>
 #include <openssl/err.h>
 #include <openssl/evp.h>
 #include <openssl/obj_mac.h>
