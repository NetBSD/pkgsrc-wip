$NetBSD$

Fix hardcoded paths.

--- ./lib/ansible/utils/module_docs_fragments/openstack.py.orig	2017-06-01 17:00:05.000000000 +0000
+++ ./lib/ansible/utils/module_docs_fragments/openstack.py
@@ -100,8 +100,8 @@ notes:
   - The standard OpenStack environment variables, such as C(OS_USERNAME)
     may be used instead of providing explicit values.
   - Auth information is driven by os-client-config, which means that values
-    can come from a yaml config file in /etc/ansible/openstack.yaml,
-    /etc/openstack/clouds.yaml or ~/.config/openstack/clouds.yaml, then from
+    can come from a yaml config file in @PKG_SYSCONFDIR@/ansible/openstack.yaml,
+    @PKG_SYSCONFDIR@/openstack/clouds.yaml or ~/.config/openstack/clouds.yaml, then from
     standard environment variables, then finally by explicit parameters in
     plays. More information can be found at
     U(http://docs.openstack.org/developer/os-client-config)
