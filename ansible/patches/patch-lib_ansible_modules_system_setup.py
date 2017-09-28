$NetBSD$

Fix hardcoded paths.

--- lib/ansible/modules/system/setup.py.orig	2017-09-19 02:57:13.000000000 +0000
+++ lib/ansible/modules/system/setup.py
@@ -55,11 +55,11 @@ options:
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
      - This module is also supported for Windows targets.
@@ -136,7 +136,7 @@ def main():
             gather_subset=dict(default=["all"], required=False, type='list'),
             gather_timeout=dict(default=10, required=False, type='int'),
             filter=dict(default="*", required=False),
-            fact_path=dict(default='/etc/ansible/facts.d', required=False, type='path'),
+            fact_path=dict(default='@PKG_SYSCONFDIR@/ansible/facts.d', required=False, type='path'),
         ),
         supports_check_mode=True,
     )
