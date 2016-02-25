$NetBSD: patch-lib_ansible_modules_extras_monitoring_nagios.py,v 1.0 2016/02/24 22:44:54 tty Exp $

Add NetBSD configuration file.

--- lib/ansible/modules/extras/monitoring/nagios.py.orig	2016-02-24 13:04:03.000000000 +0000
+++ lib/ansible/modules/extras/monitoring/nagios.py
@@ -152,6 +152,8 @@ def which_cmdfile():
         '/etc/nagios2/nagios.cfg',
         # bsd, solaris
         '/usr/local/etc/nagios/nagios.cfg',
+        # NetBSD
+        '@PKG_SYSCONFDIR@/nagios/nagios.cfg',
         # groundwork it monitoring
         '/usr/local/groundwork/nagios/etc/nagios.cfg',
         # open monitoring distribution
