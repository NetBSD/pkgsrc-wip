#!@@SH@@
#
# Run this script as root to create these necessary runtime directories.
#
install -m 0775 -o @@USER@@ -g @@GROUP@@ -d /var/log/nagios
install -m 0775 -o @@USER@@ -g @@GROUP@@ -d /var/log/nagios/archives
install -m 0775 -o @@USER@@ -g @@GROUP@@ -d /var/run/nagios
install -m 0775 -o @@USER@@ -g @@GROUP@@ -d /var/run/nagios/rw
