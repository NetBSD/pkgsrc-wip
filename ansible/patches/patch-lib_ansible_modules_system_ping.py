$NetBSD$

Fix hardcoded path.

--- lib/ansible/modules/system/ping.py.orig	2017-09-19 02:57:13.000000000 +0000
+++ lib/ansible/modules/system/ping.py
@@ -21,7 +21,7 @@ short_description: Try to connect to hos
 description:
    - A trivial test module, this module always returns C(pong) on successful
      contact. It does not make sense in playbooks, but it is useful from
-     C(/usr/bin/ansible) to verify the ability to login and that a usable python is configured.
+     C(@PREFIX@/bin/ansible) to verify the ability to login and that a usable python is configured.
    - This is NOT ICMP ping, this is just a trivial test module.
    - For Windows targets, use the M(ping) module instead.
 notes:
