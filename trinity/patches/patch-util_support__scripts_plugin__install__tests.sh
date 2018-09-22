$NetBSD$

# Unbundle slclust
--- util/support_scripts/plugin_install_tests.sh.orig	2018-09-01 15:43:40 UTC
+++ util/support_scripts/plugin_install_tests.sh
@@ -3,7 +3,7 @@
 echo "## Checking plugin installations:"
 echo
 
-if [ -e "trinity-plugins/slclust/bin/slclust" ]
+if [ -e "${LOCALBASE}/bin/slclust" ]
 then
 	echo "slclust:                 has been Installed Properly"
 else
