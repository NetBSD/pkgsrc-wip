$NetBSD$

--- ext/openssl/ossl_bn.c.orig	2011-05-20 22:25:35.000000000 +0000
+++ ext/openssl/ossl_bn.c
@@ -131,12 +131,12 @@ ossl_bn_initialize(int argc, VALUE *argv, VALUE self)
 
     switch (base) {
     case 0:
-	if (!BN_mpi2bn(RSTRING_PTR(str), RSTRING_LEN(str), bn)) {
+	if (!BN_mpi2bn((unsigned char *)RSTRING_PTR(str), RSTRING_LEN(str), bn)) {
 	    ossl_raise(eBNError, NULL);
 	}
 	break;
     case 2:
-	if (!BN_bin2bn(RSTRING_PTR(str), RSTRING_LEN(str), bn)) {
+	if (!BN_bin2bn((unsigned char *)RSTRING_PTR(str), RSTRING_LEN(str), bn)) {
 	    ossl_raise(eBNError, NULL);
 	}
 	break;
@@ -185,13 +185,13 @@ ossl_bn_to_s(int argc, VALUE *argv, VALUE self)
     case 0:
 	len = BN_bn2mpi(bn, NULL);
         str = rb_str_new(0, len);
-	if (BN_bn2mpi(bn, RSTRING_PTR(str)) != len)
+	if (BN_bn2mpi(bn, (unsigned char *)RSTRING_PTR(str)) != len)
 	    ossl_raise(eBNError, NULL);
 	break;
     case 2:
 	len = BN_num_bytes(bn);
         str = rb_str_new(0, len);
-	if (BN_bn2bin(bn, RSTRING_PTR(str)) != len)
+	if (BN_bn2bin(bn, (unsigned char *)RSTRING_PTR(str)) != len)
 	    ossl_raise(eBNError, NULL);
 	break;
     case 10:
