$NetBSD: patch-ab,v 1.8 2020/04/08 15:22:07 rhialto Exp $

- Update for openssl 1.1.1e.
- Kermit tries to keep SSL and TLS contexts (since in old openssl, the
  *v23* methods were not version-flexible enough). Now afer simplification
  there is lots of duplicate code left over that could be simplified more.

--- ck_ssl.c.orig	2017-04-26 15:56:23.000000000 +0000
+++ ck_ssl.c
@@ -303,7 +303,7 @@ X509_STORE_CTX *ctx;
                 break;
             default:
                 printf("Error %d while verifying certificate.\r\n",
-                       ctx->error);
+                       error);
                 break;
             }
         }
@@ -806,6 +806,17 @@ ssl_client_cert_callback(s, x509, pkey)
 #define MS_CALLBACK
 #endif /* MS_CALLBACK */
 
+static BIGNUM *get_RSA_F4()
+{
+    static BIGNUM *bn;
+
+    if (!bn) {
+	bn = BN_new();
+        BN_add_word(bn, RSA_F4);
+    }
+    return bn;
+}
+
 static RSA MS_CALLBACK *
 #ifdef CK_ANSIC
 tmp_rsa_cb(SSL * s, int export, int keylength)
@@ -824,7 +835,16 @@ int keylength;
         if (ssl_debug_flag)
             printf("Generating temporary (%d bit) RSA key...\r\n",keylength);
 
-        rsa_tmp=RSA_generate_key(keylength,RSA_F4,NULL,NULL);
+        rsa_tmp = RSA_new();
+	if (rsa_tmp) {
+	    int error = RSA_generate_key_ex(rsa_tmp, keylength, get_RSA_F4(),NULL);
+	    if (error) {
+		if (ssl_debug_flag)
+		    printf(" error %d", error);
+		RSA_free(rsa_tmp);
+		rsa_tmp = NULL;
+	    }
+	}
 
         if (ssl_debug_flag)
             printf("\r\n");
@@ -938,10 +958,26 @@ get_dh512()
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L    
+    BIGNUM *p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
+    BIGNUM *g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
+    if ((p == NULL) || (g == NULL)) {
+	BN_free(g);
+	BN_free(p);
+	DH_free(dh);
+        return(NULL);
+    }
+    DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
     dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+   }
+#endif
     return(dh);
 }
 
@@ -952,10 +988,26 @@ get_dh768()
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L    
+    BIGNUM *p=BN_bin2bn(dh768_p,sizeof(dh768_p),NULL);
+    BIGNUM *g=BN_bin2bn(dh768_g,sizeof(dh768_g),NULL);
+    if ((p == NULL) || (g == NULL)) {
+	BN_free(g);
+	BN_free(p);
+	DH_free(dh);
+        return(NULL);
+    }
+    DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh768_p,sizeof(dh768_p),NULL);
     dh->g=BN_bin2bn(dh768_g,sizeof(dh768_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+   }
+#endif
     return(dh);
 }
 
@@ -966,10 +1018,26 @@ get_dh1024()
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L    
+    BIGNUM *p=BN_bin2bn(dh1024_p,sizeof(dh1024_p),NULL);
+    BIGNUM *g=BN_bin2bn(dh1024_g,sizeof(dh1024_g),NULL);
+    if ((p == NULL) || (g == NULL)) {
+	BN_free(g);
+	BN_free(p);
+	DH_free(dh);
+        return(NULL);
+    }
+    DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh1024_p,sizeof(dh1024_p),NULL);
     dh->g=BN_bin2bn(dh1024_g,sizeof(dh1024_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+   }
+#endif
     return(dh);
 }
 
@@ -980,10 +1048,26 @@ get_dh1536()
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L    
+    BIGNUM *p=BN_bin2bn(dh1536_p,sizeof(dh1536_p),NULL);
+    BIGNUM *g=BN_bin2bn(dh1536_g,sizeof(dh1536_g),NULL);
+    if ((p == NULL) || (g == NULL)) {
+	BN_free(g);
+	BN_free(p);
+	DH_free(dh);
+        return(NULL);
+    }
+    DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh1536_p,sizeof(dh1536_p),NULL);
     dh->g=BN_bin2bn(dh1536_g,sizeof(dh1536_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+   }
+#endif
     return(dh);
 }
 
@@ -994,10 +1078,26 @@ get_dh2048()
 
     if ((dh=DH_new()) == NULL)
         return(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L    
+    BIGNUM *p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
+    BIGNUM *g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
+    if ((p == NULL) || (g == NULL)) {
+	BN_free(g);
+	BN_free(p);
+	DH_free(dh);
+        return(NULL);
+    }
+    DH_set0_pqg(dh, p, NULL, g);
+#else
     dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
     dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-    if ((dh->p == NULL) || (dh->g == NULL))
+    if ((dh->p == NULL) || (dh->g == NULL)) {
+        BN_free(dh->g);
+        BN_free(dh->p);
+        DH_free(dh);
         return(NULL);
+   }
+#endif
     return(dh);
 }
 #endif /* NO_DH */
@@ -1057,13 +1157,14 @@ ssl_display_comp(SSL * ssl)
         return;
 
 #ifndef OPENSSL_NO_COMP                  /* ifdefs Bernard Spil 12/2015 */
-    if (ssl->expand == NULL || ssl->expand->meth == NULL)
+    const COMP_METHOD *method = SSL_get_current_compression(ssl);
+    if (method == NULL)
 #endif /* OPENSSL_NO_COMP */
         printf("Compression: None\r\n");
 
 #ifndef OPENSSL_NO_COMP                  /* ifdefs Bernard Spil 12/2015 */
     else {
-        printf("Compression: %s\r\n",ssl->expand->meth->name);
+        printf("Compression: %s\r\n",SSL_COMP_get_name(method));
     }
 #endif /* OPENSSL_NO_COMP */
 }
@@ -1079,7 +1180,7 @@ int verbose;
 #endif /* CK_ANSIC */
 {
     X509 *peer;
-    SSL_CIPHER * cipher;
+    const SSL_CIPHER * cipher;
     const char *cipher_list;
     char buf[512]="";
 
@@ -1489,13 +1590,23 @@ the build.\r\n\r\n");
 
 #ifdef ZLIB
     cm = COMP_zlib();
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    if (cm != NULL && COMP_get_type(cm) != NID_undef) {
+#else
     if (cm != NULL && cm->type != NID_undef) {
+#endif
         SSL_COMP_add_compression_method(0xe0, cm); /* EAY's ZLIB ID */
     }
 #endif /* ZLIB */
+#ifdef NID_rle_compression
     cm = COMP_rle();
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    if (cm != NULL && COMP_get_type(cm) != NID_undef)
+#else
     if (cm != NULL && cm->type != NID_undef)
+#endif
         SSL_COMP_add_compression_method(0xe1, cm); /* EAY's RLE ID */
+#endif /* NID_rle_compression */
 
     /* Ensure the Random number generator has enough entropy */
     if ( !RAND_status() ) {
@@ -1613,12 +1724,6 @@ ssl_tn_init(mode) int mode;
             /* This can fail because we do not have RSA available */
             if ( !ssl_ctx ) {
                 debug(F110,"ssl_tn_init","SSLv23_client_method failed",0);
-#ifndef OPENSSL_NO_SSL3                  /* ifdef Bernard Spil 12/2015 */
-                ssl_ctx=(SSL_CTX *)SSL_CTX_new(SSLv3_client_method());
-#endif /* OPENSSL_NO_SSL3 */
-            }
-            if ( !ssl_ctx ) {
-                debug(F110,"ssl_tn_init","SSLv3_client_method failed",0);
                 last_ssl_mode = -1;
                 return(0);
             }
@@ -1664,12 +1769,6 @@ ssl_tn_init(mode) int mode;
             /* This can fail because we do not have RSA available */
             if ( !ssl_ctx ) {
                 debug(F110,"ssl_tn_init","SSLv23_server_method failed",0);
-#ifndef OPENSSL_NO_SSL3           /* ifdef Bernard Spil 12/2015 */
-                ssl_ctx=(SSL_CTX *)SSL_CTX_new(SSLv3_server_method());
-#endif /* OPENSSL_NO_SSL3 */
-            }
-            if ( !ssl_ctx ) {
-                debug(F110,"ssl_tn_init","SSLv3_server_method failed",0);
                 last_ssl_mode = -1;
                 return(0);
             }
@@ -1710,7 +1809,6 @@ ssl_tn_init(mode) int mode;
         SSL_CTX_set_info_callback(ssl_ctx,ssl_client_info_callback);
         SSL_CTX_set_info_callback(tls_ctx,ssl_client_info_callback);
 
-#ifndef COMMENT
         /* Set the proper caching mode */
         if ( mode == SSL_SERVER ) {
             SSL_CTX_set_session_cache_mode(ssl_ctx,SSL_SESS_CACHE_SERVER);
@@ -1721,10 +1819,6 @@ ssl_tn_init(mode) int mode;
         }
         SSL_CTX_set_session_id_context(ssl_ctx,(CHAR *)"1",1);
         SSL_CTX_set_session_id_context(tls_ctx,(CHAR *)"2",1);
-#else /* COMMENT */
-        SSL_CTX_set_session_cache_mode(ssl_ctx,SSL_SESS_CACHE_OFF);
-        SSL_CTX_set_session_cache_mode(tls_ctx,SSL_SESS_CACHE_OFF);
-#endif /* COMMENT */
     }
 
     /* The server uses defaults for the certificate files. */
@@ -1832,7 +1926,14 @@ ssl_tn_init(mode) int mode;
 
                 if ( ssl_debug_flag )
                     printf("Generating temp (512 bit) RSA key ...\r\n");
-                rsa=RSA_generate_key(512,RSA_F4,NULL,NULL);
+		rsa = RSA_new();
+		if (rsa) {
+		    int error = RSA_generate_key_ex(rsa,512,get_RSA_F4(),NULL);
+		    if (error) {
+		    	RSA_free(rsa);
+			rsa = NULL;
+		    }
+		}
                 if ( ssl_debug_flag )
                     printf("Generation of temp (512 bit) RSA key done\r\n");
 
@@ -2230,7 +2331,7 @@ ssl_http_init(hostname) char * hostname;
      * for TLS be sure to prevent use of SSLv2
      */
     SSL_CTX_set_options(tls_http_ctx,
-            SSL_OP_NO_SSLv2|SSL_OP_SINGLE_DH_USE|SSL_OP_EPHEMERAL_RSA);
+            SSL_OP_NO_SSLv2/*|SSL_OP_NO_SSLv3*/|SSL_OP_SINGLE_DH_USE|SSL_OP_EPHEMERAL_RSA);
 
     SSL_CTX_set_info_callback(tls_http_ctx,ssl_client_info_callback);
 
@@ -2623,7 +2724,11 @@ ssl_anonymous_cipher(ssl) SSL * ssl;
 int
 ssl_verify_crl(int ok, X509_STORE_CTX *ctx)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    X509_OBJECT *obj;
+#else
     X509_OBJECT obj;
+#endif
     X509_NAME *subject = NULL;
     X509_NAME *issuer = NULL;
     X509 *xs = NULL;
@@ -2643,6 +2748,14 @@ ssl_verify_crl(int ok, X509_STORE_CTX *c
     if (!crl_store)
         return ok;
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    obj = X509_OBJECT_new();
+    if (!obj)
+        return(ok);
+#else
+    memset((char *)&obj, 0, sizeof(obj));
+#endif
+
     store_ctx = X509_STORE_CTX_new();
     if ( !store_ctx )
         return(ok);
@@ -2689,11 +2802,16 @@ ssl_verify_crl(int ok, X509_STORE_CTX *c
      * Try to retrieve a CRL corresponding to the _subject_ of
      * the current certificate in order to verify it's integrity.
      */
-    memset((char *)&obj, 0, sizeof(obj));
     X509_STORE_CTX_init(store_ctx, crl_store, NULL, NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, subject, obj);
+    X509_STORE_CTX_cleanup(store_ctx);
+    crl = X509_OBJECT_get0_X509_CRL(obj);
+#else
     rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, subject, &obj);
     X509_STORE_CTX_cleanup(store_ctx);
     crl = obj.data.crl;
+#endif
     if (rc > 0 && crl != NULL) {
         /*
          * Verify the signature on this CRL
@@ -2701,7 +2819,11 @@ ssl_verify_crl(int ok, X509_STORE_CTX *c
         if (X509_CRL_verify(crl, X509_get_pubkey(xs)) <= 0) {
             fprintf(stderr, "Invalid signature on CRL!\n");
             X509_STORE_CTX_set_error(ctx, X509_V_ERR_CRL_SIGNATURE_FAILURE);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            X509_OBJECT_free(obj);
+#else
             X509_OBJECT_free_contents(&obj);
+#endif
             X509_STORE_CTX_free(store_ctx);
             return 0;
         }
@@ -2709,12 +2831,16 @@ ssl_verify_crl(int ok, X509_STORE_CTX *c
         /*
          * Check date of CRL to make sure it's not expired
          */
-        i = X509_cmp_current_time(X509_CRL_get_nextUpdate(crl));
+        i = X509_cmp_current_time(X509_CRL_get0_nextUpdate(crl));
         if (i == 0) {
             fprintf(stderr, "Found CRL has invalid nextUpdate field.\n");
             X509_STORE_CTX_set_error(ctx,
                                     X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            X509_OBJECT_free(obj);
+#else
             X509_OBJECT_free_contents(&obj);
+#endif
             X509_STORE_CTX_free(store_ctx);
             return 0;
         }
@@ -2723,22 +2849,38 @@ ssl_verify_crl(int ok, X509_STORE_CTX *c
 "Found CRL is expired - revoking all certificates until you get updated CRL.\n"
                     );
             X509_STORE_CTX_set_error(ctx, X509_V_ERR_CRL_HAS_EXPIRED);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            X509_OBJECT_free(obj);
+#else
             X509_OBJECT_free_contents(&obj);
+#endif
             X509_STORE_CTX_free(store_ctx);
             return 0;
         }
-        X509_OBJECT_free_contents(&obj);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+	X509_OBJECT_free(obj);
+#else
+	X509_OBJECT_free_contents(&obj);
+#endif
     }
 
     /*
      * Try to retrieve a CRL corresponding to the _issuer_ of
      * the current certificate in order to check for revocation.
      */
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     memset((char *)&obj, 0, sizeof(obj));
+#endif
     X509_STORE_CTX_init(store_ctx, crl_store, NULL, NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+    rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, issuer, obj);
+    X509_STORE_CTX_free(store_ctx);            /* calls X509_STORE_CTX_cleanup() */
+    crl = X509_OBJECT_get0_X509_CRL(obj);
+#else
     rc = X509_STORE_get_by_subject(store_ctx, X509_LU_CRL, issuer, &obj);
     X509_STORE_CTX_free(store_ctx);		/* calls X509_STORE_CTX_cleanup() */
     crl = obj.data.crl;
+#endif
     if (rc > 0 && crl != NULL) {
         /*
          * Check if the current certificate is revoked by this CRL
@@ -2746,19 +2888,34 @@ ssl_verify_crl(int ok, X509_STORE_CTX *c
         n = sk_X509_REVOKED_num(X509_CRL_get_REVOKED(crl));
         for (i = 0; i < n; i++) {
             revoked = sk_X509_REVOKED_value(X509_CRL_get_REVOKED(crl), i);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+            if (ASN1_INTEGER_cmp(X509_REVOKED_get0_serialNumber(revoked),
+                                 X509_get_serialNumber(xs)) == 0) { // }
+
+                serial = ASN1_INTEGER_get(X509_REVOKED_get0_serialNumber(revoked));
+#else
             if (ASN1_INTEGER_cmp(revoked->serialNumber,
                                  X509_get_serialNumber(xs)) == 0) {
 
                 serial = ASN1_INTEGER_get(revoked->serialNumber);
+#endif
                 cp = X509_NAME_oneline(issuer, NULL, 0);
                 free(cp);
 
                 X509_STORE_CTX_set_error(ctx, X509_V_ERR_CERT_REVOKED);
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+                X509_OBJECT_free(obj);
+#else
                 X509_OBJECT_free_contents(&obj);
+#endif
                 return 0;
             }
         }
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+	X509_OBJECT_free(obj);
+#else
         X509_OBJECT_free_contents(&obj);
+#endif
     }
     return ok;
 }
@@ -2929,6 +3086,7 @@ show_hostname_warning(char *s1, char *s2
 #ifndef OpenBSD
 #ifndef FREEBSD4
 #ifndef NETBSD15
+#ifndef __DragonFly__
 #ifndef LINUX
 #ifndef AIX41
 #ifndef UW7
@@ -2971,6 +3129,7 @@ inet_aton(char * ipaddress, struct in_ad
 #endif /* UW7 */
 #endif /* AIX41 */
 #endif /* LINUX */
+#endif /* __DragonFly__ */
 #endif /* NETBSD15 */
 #endif /* FREEBSD4 */
 #endif /* OpenBSD */
@@ -3113,7 +3272,7 @@ int
 tls_is_anon(int x)
 {
     char buf[128];
-    SSL_CIPHER * cipher;
+    const SSL_CIPHER * cipher;
     SSL * ssl = NULL;
 
     switch ( x ) {
@@ -3157,7 +3316,7 @@ int
 tls_is_krb5(int x)
 {
     char buf[128];
-    SSL_CIPHER * cipher;
+    const SSL_CIPHER * cipher;
     SSL * ssl = NULL;
 
     switch ( x ) {
@@ -4399,7 +4558,14 @@ X509_userok(X509 * peer_cert, const char
     if (!(fp = fopen(buf, "r")))
         return 0;
     while (!r && (file_cert = PEM_read_X509(fp, NULL, NULL, NULL))) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        const ASN1_BIT_STRING *peer_cert_sig, *file_cert_sig;
+        X509_get0_signature(&peer_cert_sig, NULL, peer_cert);
+        X509_get0_signature(&file_cert_sig, NULL, file_cert);
+        if (!ASN1_STRING_cmp(peer_cert_sig, file_cert_sig))
+#else
         if (!ASN1_STRING_cmp(peer_cert->signature, file_cert->signature))
+#endif
             r = 1;
         X509_free(file_cert);
     }
