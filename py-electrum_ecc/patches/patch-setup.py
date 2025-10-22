$NetBSD$

Use gmake for pkgsrc builds.

--- setup.py.orig	2000-11-11 11:11:11.000000000 +0000
+++ setup.py
@@ -34,7 +34,7 @@ except ImportError as e1:
 
 
 _logger = logging.getLogger("electrum_ecc")
-MAKE = 'gmake' if platform.system() in ['FreeBSD', 'OpenBSD'] else 'make'
+MAKE = 'gmake' if platform.system() in ['FreeBSD', 'OpenBSD', 'NetBSD', 'Darwin', 'SunOS'] else 'make'
 
 ELECTRUM_ECC_DONT_COMPILE = None
 for arg in sys.argv[:]:
