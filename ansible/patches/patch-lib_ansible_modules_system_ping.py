$NetBSD$

Fix hardcoded path.

--- ./lib/ansible/modules/system/ping.py.orig	2017-06-01 17:00:05.000000000 +0000
+++ ./lib/ansible/modules/system/ping.py
@@ -33,7 +33,7 @@ short_description: Try to connect to hos
 description:
    - A trivial test module, this module always returns C(pong) on successful
      contact. It does not make sense in playbooks, but it is useful from
-     C(/usr/bin/ansible) to verify the ability to login and that a usable python is configured.
+     C(@PREFIX@/bin/ansible) to verify the ability to login and that a usable python is configured.
    - This is NOT ICMP ping, this is just a trivial test module.
 options: {}
 author:
