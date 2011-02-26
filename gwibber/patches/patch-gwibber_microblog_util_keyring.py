$NetBSD: patch-gwibber_microblog_util_keyring.py,v 1.2 2011/02/26 11:56:25 ryo-on Exp $

* for non-Linux platform.

--- gwibber/microblog/util/keyring.py.orig	2011-01-09 06:12:03.000000000 +0000
+++ gwibber/microblog/util/keyring.py
@@ -17,7 +17,7 @@ def get_secret(id):
 
   return value
 
-libc = ctypes.CDLL("libc.so.6")
+libc = ctypes.CDLL("libc.so")
 
 def mlock(var):
     libc.mlock(var, len(var))
