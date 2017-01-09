$NetBSD: patch-lib_ansible_modules_core_system_setup.py,v 1.0 2016/02/24 22:44:47 tty Exp $

Fix hardcoded paths.

--- lib/ansible/modules/core/system/setup.py.orig	2016-05-25 13:00:59.000000000 +0000
+++ lib/ansible/modules/core/system/setup.py
@@ -57,11 +57,11 @@ options:
               if a file is not executable it is read. Check notes for Windows options. (from 2.1 on)
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
@@ -119,7 +119,7 @@ def main():
             gather_subset=dict(default=["all"], required=False, type='list'),
             gather_timeout=dict(default=10, required=False, type='int'),
             filter=dict(default="*", required=False),
-            fact_path=dict(default='/etc/ansible/facts.d', required=False),
+            fact_path=dict(default='@PKG_SYSCONFDIR@/ansible/facts.d', required=False),
         ),
         supports_check_mode = True,
     )
