$NetBSD$

Relax the dependency on devel/py-futures

--- setup.py.orig	2019-05-13 12:54:51.000000000 +0000
+++ setup.py
@@ -56,7 +56,7 @@ INSTALL_REQUIRES = [
 	"scandir>=1.10,<1.11",
 	"websocket-client>=0.56,<0.57",
 	"wrapt>=1.11.1,<1.12",
-	"futures>=3.2,<3.3",
+	"futures>=3.2,<3.4",
 	"emoji>=0.5.1,<0.6",
 	"monotonic>=1.5,<1.6",
 	"frozendict>=1.2,<1.3",
