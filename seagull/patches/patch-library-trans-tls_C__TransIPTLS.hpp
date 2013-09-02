$NetBSD: patch-library-trans-tls_C__TransIPTLS.hpp,v 1.1 2013/09/02 19:08:25 thomasklausner Exp $

Fix build with newer openssl (avoid casting const away).

--- library-trans-tls/C_TransIPTLS.hpp.orig	2010-10-27 12:30:16.000000000 +0000
+++ library-trans-tls/C_TransIPTLS.hpp
@@ -38,7 +38,7 @@ public:
 
   virtual int         config (T_pConfigValueList P_config_param_list) ;
 
-  typedef SSL_METHOD* (*T_SSLMethodType)(void); 
+  typedef const SSL_METHOD* (*T_SSLMethodType)(void); 
   typedef struct _T_supported_methods {
     char *m_name ;
     T_SSLMethodType m_method ;
