$NetBSD: patch-contrib_inventory_nova.py,v 1.0 2016/02/24 22:43:07 tty Exp $

Fix hardcoded path.

--- contrib/inventory/nova.py.orig	2016-02-24 13:04:04.000000000 +0000
+++ contrib/inventory/nova.py
@@ -42,7 +42,7 @@ sys.stderr.write("WARNING: this inventor
 
 NOVA_CONFIG_FILES = [os.getcwd() + "/nova.ini",
                      os.path.expanduser(os.environ.get('ANSIBLE_CONFIG', "~/nova.ini")),
-                     "/etc/ansible/nova.ini"]
+                     "@PKG_SYSCONFDIR@/ansible/nova.ini"]
 
 NOVA_DEFAULTS = {
     'auth_system': None,
