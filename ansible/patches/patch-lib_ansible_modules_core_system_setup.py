$NetBSD: patch-lib_ansible_modules_core_system_setup.py,v 1.0 2016/02/24 22:44:47 tty Exp $

Fix hardcoded paths.

--- lib/ansible/modules/core/system/setup.py.orig	2016-02-24 13:04:03.000000000 +0000
+++ lib/ansible/modules/core/system/setup.py
@@ -38,11 +38,11 @@ options:
               if a file is not executable it is read.
               File/results format can be json or ini-format
         required: false
-        default: '/etc/ansible/facts.d'
+        default: '@PKG_SYSCONFDIR@/ansible/facts.d'
 description:
      - This module is automatically called by playbooks to gather useful
        variables about remote hosts that can be used in playbooks. It can also be
-       executed directly by C(/usr/bin/ansible) to check what variables are
+       executed directly by C(@PREFIX@/bin/ansible) to check what variables are
        available to a host. Ansible provides many I(facts) about the system,
        automatically.
 notes:
@@ -132,7 +132,7 @@ def main():
     module = AnsibleModule(
         argument_spec = dict(
             filter=dict(default="*", required=False),
-            fact_path=dict(default='/etc/ansible/facts.d', required=False),
+            fact_path=dict(default='@PKG_SYSCONFDIR@/ansible/facts.d', required=False),
         ),
         supports_check_mode = True,
     )
