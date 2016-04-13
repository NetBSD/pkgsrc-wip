$NetBSD$

Avoid duplicate symbols.

--- egg/egg-asn1x.h.orig	2014-09-23 07:40:08.000000000 +0000
+++ egg/egg-asn1x.h
@@ -67,7 +67,7 @@ typedef enum {
 	EGG_ASN1X_GENERALIZED_TIME = 37,
 } EggAsn1xType;
 
-enum {
+extern enum {
 	EGG_ASN1X_NO_STRICT = 0x01,
 } EggAsn1xFlags;
 
