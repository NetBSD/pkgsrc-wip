$NetBSD$

Relax some dependencies

--- setup.py.orig	2019-10-21 10:27:16.000000000 +0000
+++ setup.py
@@ -20,12 +20,12 @@ INSTALL_REQUIRES = [
 	# the following dependencies are non trivial to update since later versions introduce backwards incompatible
 	# changes that might affect plugins, or due to other observed problems
 
-	"flask>=0.10.1,<0.11",         # newer versions require newer Jinja versions
-	"Jinja2>=2.8.1,<2.9",          # Jinja 2.9 has breaking changes WRT template scope - we can't
+	"flask>=0.10.1",         # versions >= 0.11 require newer Jinja versions
+	"Jinja2>=2.8.1,<2.11",          # Jinja 2.9 has breaking changes WRT template scope - we can't
 	                               # guarantee backwards compatibility for plugins and such with that
 	                               # version, hence we need to pin to a lower version for now. See #1697
-	"tornado==4.5.3",              # a memory leak was observed in tornado >= 5, see #2585
-	"Flask-Login>=0.2.11,<0.3",    # some functions changed to properties in 0.3
+	"tornado>=4.5.3",              # a memory leak was observed in tornado >= 5, see #2585
+	"Flask-Login>=0.2.11,<0.5",    # some functions changed to properties in 0.3
 	"regex!=2018.11.6",            # avoid broken 2018.11.6. See #2874
 
 	# anything below this should be checked on releases for new versions
@@ -36,7 +36,7 @@ INSTALL_REQUIRES = [
 	"werkzeug>=0.15.1,<0.16",
 	"cachelib>=0.1,<0.2",
 	"PyYAML>=5.1,<6",
-	"markdown>=3.0,<3.1",
+	"markdown>=3.0,<3.2",
 	"pyserial>=3.4,<3.5",
 	"netaddr>=0.7.19,<0.8",
 	"watchdog>=0.9.0,<0.10",
@@ -46,7 +46,7 @@ INSTALL_REQUIRES = [
 	"rsa>=4.0,<5",
 	"pkginfo>=1.5.0.1,<1.6",
 	"requests>=2.21.0,<3",
-	"semantic_version>=2.6,<2.7",
+	"semantic_version>=2.6,<2.9",
 	"psutil>=5.6.1,<5.7",
 	"Click>=7,<8",
 	"awesome-slugify>=1.6.5,<1.7",
@@ -56,7 +56,7 @@ INSTALL_REQUIRES = [
 	"scandir>=1.10,<1.11",
 	"websocket-client>=0.56,<0.57",
 	"wrapt>=1.11.1,<1.12",
-	"futures>=3.2,<3.3",
+	"futures>=3.2,<3.4",
 	"emoji>=0.5.1,<0.6",
 	"monotonic>=1.5,<1.6",
 	"frozendict>=1.2,<1.3",
