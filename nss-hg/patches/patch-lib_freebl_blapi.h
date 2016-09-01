$NetBSD: patch-lib_freebl_blapi.h,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

Avoid namespace collision (?)

--- lib/freebl/blapi.h.orig	2016-08-31 09:42:50.000000000 +0000
+++ lib/freebl/blapi.h
@@ -12,6 +12,8 @@
 #include "hasht.h"
 #include "alghmac.h"
 
+#define SHA1_Update NSS_SHA1_Update
+
 SEC_BEGIN_PROTOS
 
 /*
