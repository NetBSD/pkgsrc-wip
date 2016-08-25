$NetBSD$

Fix to correctly return "set" command variant of config.
Ref. https://github.com/ansible/ansible/issues/17111

--- lib/ansible/module_utils/junos.py.orig  2016-06-24 16:26:59.000000000 +0200
+++ lib/ansible/module_utils/junos.py    2016-08-25 11:12:20.000000000 +0200
@@ -259,11 +259,14 @@ class Netconf(object):
             msg = 'invalid config format... must be one of xml, text, set'
             self._fail(msg=msg)
 
-        ele = self.rpc('get_configuration', format=config_format)
-        if config_format in ['text', 'set']:
-           return str(ele.text).strip()
-        elif config_format == "xml":
-            return ele
+        if config_format == 'set':
+            return self.run_commands(('show configuration | display set'))[0].strip()
+        else:
+            ele = self.rpc('get_configuration', format=config_format)
+            if config_format in ['text', 'set']:
+                return str(ele.text).strip()
+            elif config_format == "xml":
+                return ele
 
     def rpc(self, name, format='xml', **kwargs):
         meth = getattr(self.device.rpc, name)
