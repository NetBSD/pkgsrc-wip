$NetBSD: patch-lib_ansible_modules_core_system_ping.py,v 1.0 2016/02/24 22:44:41 tty Exp $

Fix hardcoded path.

--- lib/ansible/modules/core/system/ping.py.orig	2016-02-24 13:04:03.000000000 +0000
+++ lib/ansible/modules/core/system/ping.py
@@ -27,7 +27,7 @@ short_description: Try to connect to hos
 description:
    - A trivial test module, this module always returns C(pong) on successful
      contact. It does not make sense in playbooks, but it is useful from
-     C(/usr/bin/ansible) to verify the ability to login and that a usable python is configured.
+     C(@PREFIX@/bin/ansible) to verify the ability to login and that a usable python is configured.
    - This is NOT ICMP ping, this is just a trivial test module.
 options: {}
 author:
