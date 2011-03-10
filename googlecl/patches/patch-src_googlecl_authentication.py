$NetBSD: patch-src_googlecl_authentication.py,v 1.1.1.1 2011/03/10 13:35:51 ryo-on Exp $

http://code.google.com/p/googlecl/source/detail?r=540

--- src/googlecl/authentication.py.orig	2010-11-22 16:07:26.000000000 +0000
+++ src/googlecl/authentication.py
@@ -44,7 +44,8 @@ class AuthenticationManager(object):
       self.tokens_path = tokens_path
     else:
       self.tokens_path = googlecl.get_data_path(TOKENS_FILENAME_FORMAT %
-                                                client.email)
+                                                client.email,
+						create_missing_dir=True)
 
   def check_access_token(self):
     """Checks that the client's access token is valid, remove it if not.
