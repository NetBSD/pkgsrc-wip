$NetBSD$

Fix hardcoded paths.

--- ./lib/ansible/modules/system/setup.py.orig	2017-06-01 17:00:05.000000000 +0000
+++ ./lib/ansible/modules/system/setup.py
@@ -62,11 +62,11 @@ options:
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
@@ -124,7 +124,7 @@ def main():
             gather_subset=dict(default=["all"], required=False, type='list'),
             gather_timeout=dict(default=10, required=False, type='int'),
             filter=dict(default="*", required=False),
-            fact_path=dict(default='/etc/ansible/facts.d', required=False, type='path'),
+            fact_path=dict(default='@PKG_SYSCONFDIR@/ansible/facts.d', required=False, type='path'),
         ),
         supports_check_mode = True,
     )
