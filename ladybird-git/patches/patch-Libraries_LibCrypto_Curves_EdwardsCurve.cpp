$NetBSD$

--- Libraries/LibCrypto/Curves/EdwardsCurve.cpp.orig	2025-05-09 07:51:13.462450630 +0000
+++ Libraries/LibCrypto/Curves/EdwardsCurve.cpp
@@ -50,10 +50,6 @@ ErrorOr<ByteBuffer> SignatureEdwardsCurv
         OSSL_PARAM_END
     };
 
-    if (!context.is_null()) {
-        params[0] = OSSL_PARAM_octet_string(OSSL_SIGNATURE_PARAM_CONTEXT_STRING, const_cast<u8*>(context.data()), context.size());
-    }
-
     OPENSSL_TRY(EVP_DigestSignInit_ex(ctx.ptr(), nullptr, nullptr, nullptr, nullptr, key.ptr(), params));
 
     size_t sig_len = 0;
@@ -77,7 +73,7 @@ ErrorOr<bool> SignatureEdwardsCurve::ver
     };
 
     if (!context.is_null()) {
-        params[0] = OSSL_PARAM_octet_string(OSSL_SIGNATURE_PARAM_CONTEXT_STRING, const_cast<u8*>(context.data()), context.size());
+        return false;
     }
 
     OPENSSL_TRY(EVP_DigestVerifyInit_ex(ctx.ptr(), nullptr, nullptr, nullptr, nullptr, key.ptr(), params));
