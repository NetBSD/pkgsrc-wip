$NetBSD$

Avoid duplicate symbols.

--- gcr/gcr-certificate.h.orig	2014-09-23 07:40:08.000000000 +0000
+++ gcr/gcr-certificate.h
@@ -149,6 +149,8 @@ void                gcr_certificate_mixi
                                                             GValue *value,
                                                             GParamSpec *pspec);
 
+enum EggAsn1xFlags;
+
 G_END_DECLS
 
 #endif /* __GCR_CERTIFICATE_H__ */
