$NetBSD$

Add NetBSD configuration file.

--- ./lib/ansible/modules/monitoring/nagios.py.orig	2017-06-01 17:00:05.000000000 +0000
+++ ./lib/ansible/modules/monitoring/nagios.py
@@ -216,6 +216,8 @@ def which_cmdfile():
         '/etc/nagios2/nagios.cfg',
         # bsd, solaris
         '/usr/local/etc/nagios/nagios.cfg',
+        # NetBSD
+        '@PKG_SYSCONFDIR@/nagios/nagios.cfg',
         # groundwork it monitoring
         '/usr/local/groundwork/nagios/etc/nagios.cfg',
         # open monitoring distribution
