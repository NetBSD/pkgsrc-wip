$NetBSD: patch-contrib_README.md,v 1.0 2016/02/24 22:42:47 tty Exp $

Fix hardcoded path.

--- contrib/README.md.orig	2017-09-19 02:57:13.000000000 +0000
+++ contrib/README.md
@@ -11,7 +11,7 @@ Before 2.4 introduced inventory plugins,
 Starting with Ansible version 2.4, they are enabled via the 'script' inventory plugin.
 Examples of use include discovering inventory from EC2 or pulling it from Cobbler. These could also be used to interface with LDAP or the database.
 
-`chmod +x` an inventory plugin and either name it `/etc/ansible/hosts` or use `ansible -i /path/to/inventory/script`. You might also need to copy a configuration file with the same name and/or set environment variables. The scripts or configuration files can provide more details.
+`chmod +x` an inventory plugin and either name it `@PKG_SYSCONFDIR@/ansible/hosts` or use `ansible -i /path/to/inventory/script`. You might also need to copy a configuration file with the same name and/or set environment variables. The scripts or configuration files can provide more details.
 
 vault
 =====
