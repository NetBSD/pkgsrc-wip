$NetBSD: patch-lib_ansible_cli_galaxy.py,v 1.0 2016/02/24 22:44:30 tty Exp $

Fix hardcoded path.

--- lib/ansible/cli/galaxy.py.orig	2016-02-24 13:57:06.000000000 +0000
+++ lib/ansible/cli/galaxy.py
@@ -122,7 +122,7 @@ class GalaxyCLI(CLI):
             self.parser.add_option('-p', '--roles-path', dest='roles_path', default=C.DEFAULT_ROLES_PATH,
                 help='The path to the directory containing your roles. '
                      'The default is the roles_path configured in your '
-                     'ansible.cfg file (/etc/ansible/roles if not configured)')
+                     'ansible.cfg file (@PKG_SYSCONFDIR@/ansible/roles if not configured)')
 
         if self.action in ("import","info","init","install","login","search","setup","delete"):
             self.parser.add_option('-s', '--server', dest='api_server', default=C.GALAXY_SERVER,
