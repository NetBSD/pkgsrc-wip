$NetBSD: patch-contrib_inventory_openstack.py,v 1.0 2016/02/24 22:43:12 tty Exp $

Fix hardcoded path.

--- contrib/inventory/openstack.py.orig	2016-02-24 13:04:04.000000000 +0000
+++ contrib/inventory/openstack.py
@@ -26,7 +26,7 @@
 #  - Current directory
 #  - ~/.config/openstack/clouds.yaml
 #  - /etc/openstack/clouds.yaml
-#  - /etc/ansible/openstack.yml
+#  - @PKG_SYSCONFDIR@/ansible/openstack.yml
 # The clouds.yaml file can contain entries for multiple clouds and multiple
 # regions of those clouds. If it does, this inventory module will connect to
 # all of them and present them as one contiguous inventory.
@@ -55,7 +55,7 @@ import os_client_config
 import shade
 import shade.inventory
 
-CONFIG_FILES = ['/etc/ansible/openstack.yaml']
+CONFIG_FILES = ['@PKG_SYSCONFDIR@/ansible/openstack.yaml']
 
 
 def get_groups_from_server(server_vars, namegroup=True):
