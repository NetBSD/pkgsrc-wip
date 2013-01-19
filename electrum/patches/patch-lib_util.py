$NetBSD: patch-lib_util.py,v 1.1 2013/01/19 04:44:22 akihabara Exp $

--- lib/util.py.orig	2013-01-19 02:23:59.821272000 +0000
+++ lib/util.py
@@ -87,7 +87,8 @@ def appdata_dir():
     elif platform.system() == "Linux":
         return os.path.join(sys.prefix, "share", "electrum")
     elif (platform.system() == "Darwin" or
-          platform.system() == "DragonFly"):
+          platform.system() == "DragonFly" or
+	  platform.system() == "NetBSD"):
         return "/Library/Application Support/Electrum"
     else:
         raise Exception("Unknown system")
