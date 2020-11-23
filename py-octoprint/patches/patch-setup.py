$NetBSD$

Override some version checks

--- setup.py.orig	2020-08-06 10:41:11.000000000 +0000
+++ setup.py
@@ -33,7 +33,7 @@ INSTALL_REQUIRES = [
 	"markupsafe>=1.1,<2.0",      # Jinja dependency, newer versions require Python 3
 	"tornado==5.1.1",            # newer versions require Python 3
 	"markdown>=3.1,<3.2",        # newer versions require Python 3
-	"rsa==4.0",                  # newer versions require Python 3
+	"rsa>=4.0",                  # newer versions require Python 3
 	"regex!=2018.11.6",          # avoid broken 2018.11.6. See #2874
 
 	# anything below this should be checked on releases for new versions
@@ -68,7 +68,7 @@ INSTALL_REQUIRES = [
 	"filetype>=1.0.7,<2",
 
 	# vendor bundle dependencies
-	"unidecode>=0.04.14,<0.05",  # dependency of awesome-slugify
+	"unidecode>=0.04.14",  # dependency of awesome-slugify
 	"blinker>=1.4,<2"            # dependency of flask_principal
 ]
 
