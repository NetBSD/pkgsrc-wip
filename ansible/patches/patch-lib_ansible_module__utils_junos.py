$NetBSD$

Add fix related to ansible bugid 3962.

--- lib/ansible/module_utils/junos.py.orig	2016-05-25 13:00:55.000000000 +0000
+++ lib/ansible/module_utils/junos.py
@@ -261,7 +261,7 @@ class Netconf(object):
 
         ele = self.rpc('get_configuration', format=config_format)
         if config_format in ['text', 'set']:
-           return str(ele.text).strip()
+           return unicode(ele.text).strip()
         elif config_format == "xml":
             return ele
 
