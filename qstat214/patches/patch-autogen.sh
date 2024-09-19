--- autogen.sh	2019-02-28 03:12:51.961531647 +0100
+++ autogen.sh	2019-02-28 03:11:36.870526291 +0100
@@ -1,11 +1,11 @@
 #!/bin/sh
 
 # Global variables...
-AUTOCONF="autoconf"
-AUTOHEADER="autoheader"
-AUTOM4TE="autom4te"
-AUTOMAKE="automake"
-ACLOCAL="aclocal"
+AUTOCONF="/usr/pkg/bin/autoconf"
+AUTOHEADER="/usr/pkg/bin/autoheader"
+AUTOM4TE="/usr/pkg/bin/autom4te"
+AUTOMAKE="/usr/pkg/bin/automake"
+ACLOCAL="/usr/pkg/bin/aclocal"
 
 # Please add higher versions first. The last version number is the minimum
 # needed to compile KDE. Do not forget to include the name/version #
