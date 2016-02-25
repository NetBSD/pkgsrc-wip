$NetBSD: patch-contrib_inventory_cobbler.py,v 1.0 2016/02/24 22:42:54 tty Exp $

Fix hardcoded paths.

--- contrib/inventory/cobbler.py.orig	2016-02-24 13:04:04.000000000 +0000
+++ contrib/inventory/cobbler.py
@@ -4,11 +4,11 @@
 Cobbler external inventory script
 =================================
 
-Ansible has a feature where instead of reading from /etc/ansible/hosts
+Ansible has a feature where instead of reading from @PKG_SYSCONFDIR@/ansible/hosts
 as a text file, it can query external programs to obtain the list
 of hosts, groups the hosts are in, and even variables to assign to each host.
 
-To use this, copy this file over /etc/ansible/hosts and chmod +x the file.
+To use this, copy this file over @PKG_SYSCONFDIR@/ansible/hosts and chmod +x the file.
 This, more or less, allows you to keep one central database containing
 info about all of your managed instances.
 
