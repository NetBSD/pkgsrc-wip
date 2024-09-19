$NetBSD: patch-wifite.py,v 1.1 2013/05/26 01:53:39 othyro Exp $

Add NetBSD support.

--- wifite.py.orig	2012-08-04 18:33:12.000000000 +0000
+++ wifite.py
@@ -167,7 +167,7 @@ if os.getuid() != 0:
 	print R+' [!]'+O+' login as root ('+W+'su root'+O+') or try '+W+'sudo ./wifite.py'+W
 	exit(1)
 
-if not os.uname()[0].startswith("Linux") and not 'Darwin' in os.uname()[0]: # OSX support, 'cause why not?
+if not os.uname()[0].startswith("Linux") and not 'NetBSD' in os.uname()[0] and not 'Darwin' in os.uname()[0]: # OSX support, 'cause why not?
 	print O+' [!]'+R+' WARNING:'+G+' wifite'+W+' must be run on '+O+'linux'+W
 	exit(1)
 
