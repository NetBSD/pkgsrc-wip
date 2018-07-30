$NetBSD$

Added config structure element for Cancel-Lock hash algorithm.

--- src/misc.h.orig	2016-10-23 22:34:16.000000000 +0000
+++ src/misc.h
@@ -80,6 +80,7 @@ typedef struct
    char *signature;
 #if SLRN_HAS_CANLOCK
    char *cancelsecret;
+   char *canlock_algo;
 #endif
    char *posting_host;		       /* FQDN or NULL */
    char *login_name;
