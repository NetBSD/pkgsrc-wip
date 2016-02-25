$NetBSD: patch-contrib_inventory_collins.py,v 1.0 2016/02/24 22:43:01 tty Exp $

Fix hardcoded paths.

--- contrib/inventory/collins.py.orig	2016-02-24 13:04:04.000000000 +0000
+++ contrib/inventory/collins.py
@@ -4,7 +4,7 @@
 Collins external inventory script
 =================================
 
-Ansible has a feature where instead of reading from /etc/ansible/hosts
+Ansible has a feature where instead of reading from @PKG_SYSCONFDIR@/ansible/hosts
 as a text file, it can query external programs to obtain the list
 of hosts, groups the hosts are in, and even variables to assign to each host.
 
@@ -25,7 +25,7 @@ Cobbler inventory script.
 
 To use it, copy it to your repo and pass -i <collins script> to the ansible or
 ansible-playbook command; if you'd like to use it by default, simply copy collins.ini
-to /etc/ansible and this script to /etc/ansible/hosts.
+to @PKG_SYSCONFDIR@/ansible and this script to @PKG_SYSCONFDIR@/ansible/hosts.
 
 Alongside the options set in collins.ini, there are several environment variables
 that will be used instead of the configured values if they are set:
