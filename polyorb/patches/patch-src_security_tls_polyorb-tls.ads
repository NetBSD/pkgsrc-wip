$NetBSD: patch-src_security_tls_polyorb-tls.adb,v 1.0 2024/12/17 20:00:00 dkazankov Exp $

Fix deprecated init function

--- src/security/tls/polyorb-tls.ads.orig	2024-08-23 19:03:44.000000000 +0300
+++ src/security/tls/polyorb-tls.ads
@@ -50,6 +50,8 @@
 
    type TLS_Verification_Mode is array (TLS_Verification_Mode_Flag) of Boolean;
 
+   type INIT_SETTINGS_ACCESS is private;
+
    type TLS_Context_Type is private;
 
    type TLS_Cipher_Type is private;
@@ -189,6 +191,10 @@
 
 private
 
+   type OPENSSL_INIT_SETTINGS is null record;
+   pragma Convention (C, OPENSSL_INIT_SETTINGS);
+   type INIT_SETTINGS_ACCESS is access all OPENSSL_INIT_SETTINGS;
+
    --  TLS Context
 
    type TLS_Context_Record is null record;
