$NetBSD: patch-contrib_inventory_openstack.py,v 1.0 2016/02/24 22:43:12 tty Exp $

Fix hardcoded path.

--- contrib/inventory/openstack.py.orig	2016-05-25 13:00:55.000000000 +0000
+++ contrib/inventory/openstack.py
@@ -26,8 +26,8 @@
 # If you want to configure via clouds.yaml, you can put the file in:
 #  - Current directory
 #  - ~/.config/openstack/clouds.yaml
-#  - /etc/openstack/clouds.yaml
-#  - /etc/ansible/openstack.yml
+#  - @PKG_SYSCONFDIR@/openstack/clouds.yaml
+#  - @PKG_SYSCONFDIR@/ansible/openstack.yml
 # The clouds.yaml file can contain entries for multiple clouds and multiple
 # regions of those clouds. If it does, this inventory module will by default
 # connect to all of them and present them as one contiguous inventory.  You
@@ -67,7 +67,7 @@ import os_client_config
 import shade
 import shade.inventory
 
-CONFIG_FILES = ['/etc/ansible/openstack.yaml', '/etc/ansible/openstack.yml']
+CONFIG_FILES = ['@PKG_SYSCONFDIR@/ansible/openstack.yaml', '@PKG_SYSCONFDIR@/ansible/openstack.yml']
 
 
 def get_groups_from_server(server_vars, namegroup=True):
