$NetBSD$

Add NETCONF RPC timeout beyond the default value of
30 seconds. Set this value to accommodate configuration
changes (commits) that might take longer than the default
timeout interval.

From https://github.com/ganeshnalawade/ansible-modules-core/commit/da4105a45615bd59bcc138ab926765ef8bdd5cff

--- lib/ansible/modules/core/network/junos/junos_config.py.orig	2016-11-01 03:43:28.000000000 +0000
+++ lib/ansible/modules/core/network/junos/junos_config.py
@@ -113,6 +113,14 @@ options:
     default: no
     choices: ['yes', 'no']
     version_added: "2.2"
+  timeout:
+    description:
+      - Extend the NETCONF RPC timeout beyond the default value of
+        30 seconds. Set this value to accommodate configuration
+        changes (commits) that might take longer than the default
+        timeout interval.
+    required: false
+    default: 0
 requirements:
   - junos-eznc
 notes:
@@ -133,6 +141,7 @@ vars:
   junos_config:
     src: srx.cfg
     comment: update config
+    timeout: 60
     provider: "{{ netconf }}"
 
 - name: rollback the configuration to id 10
@@ -231,7 +240,7 @@ def diff_commands(commands, config):
     return updates
 
 def load_config(module, result):
-    candidate =  module.params['lines'] or module.params['src']
+    candidate = module.params['lines'] or module.params['src']
     if isinstance(candidate, basestring):
         candidate = candidate.split('\n')
 
@@ -282,6 +291,10 @@ def confirm_config(module, result):
     result['changed'] = module.connection.confirm_commit(checkonly)
 
 def run(module, result):
+    timeout = module.params['timeout']
+    if timeout > 0 and module.params['transport'] == 'netconf':
+        module.connection.device.timeout = timeout
+
     if module.params['rollback']:
         return rollback_config(module, result)
     elif module.params['zeroize']:
@@ -311,6 +324,9 @@ def main():
         rollback=dict(type='int'),
         zeroize=dict(default=False, type='bool'),
 
+        # timeout
+        timeout=dict(default=0, type='int'),
+
         transport=dict(default='netconf', choices=['netconf'])
     )
 
