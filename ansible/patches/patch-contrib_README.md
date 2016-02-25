$NetBSD: patch-contrib_README.md,v 1.0 2016/02/24 22:42:47 tty Exp $

Fix hardcoded path.

--- contrib/README.md.orig	2016-01-14 22:33:27.000000000 +0000
+++ contrib/README.md
@@ -5,7 +5,7 @@ Inventory scripts allow you to store you
 you like.  Examples include discovering inventory from EC2 or pulling it from
 Cobbler.  These could also be used to interface with LDAP or database.
 
-chmod +x an inventory plugin and either name it /etc/ansible/hosts or use ansible
+chmod +x an inventory plugin and either name it @PKG_SYSCONFDIR@/ansible/hosts or use ansible
 with -i to designate the path to the script. You might also need to copy a configuration
 file with the same name and/or set environment variables, the scripts or configuration
 files have more details.
