$NetBSD: patch-gwibber_microblog_util_keyring.py,v 1.1 2011/02/15 20:57:52 ryo-on Exp $

--- gwibber/microblog/util/keyring.py.orig	2010-12-14 20:13:35.000000000 +0000
+++ gwibber/microblog/util/keyring.py
@@ -17,7 +17,7 @@ def get_secret(id):
 
   return value
 
-libc = ctypes.CDLL("libc.so.6")
+libc = ctypes.CDLL("libc.so")
 
 def mlock(var):
     libc.mlock(var, len(var))
