$NetBSD$

Remove unused include.
https://github.com/indygreg/PyOxidizer/pull/623

--- src/cryptography.rs.orig	2022-08-07 20:37:36.000000000 +0000
+++ src/cryptography.rs
@@ -10,7 +10,7 @@ use {
         AppleCodesignError,
     },
     bytes::Bytes,
-    der::{asn1, Decodable, Document, Encodable},
+    der::{asn1, Document, Encodable},
     elliptic_curve::{
         sec1::{FromEncodedPoint, ModulusSize, ToEncodedPoint},
         AffinePoint, Curve, FieldSize, ProjectiveArithmetic, SecretKey as ECSecretKey,
