$NetBSD$

Add fix related to ansible bugid 3962.  

--- lib/ansible/modules/core/network/junos/junos_template.py.orig	2016-05-25 13:00:59.000000000 +0000
+++ lib/ansible/modules/core/network/junos/junos_template.py
@@ -132,7 +132,7 @@ def main():
             "set per junos documentation")
 
     results = dict(changed=False)
-    results['_backup'] = str(module.get_config()).strip()
+    results['_backup'] = unicode(module.get_config()).strip()
 
     diff = module.load_config(src, action=action, comment=comment,
             format=fmt, commit=commit, confirm=confirm)
