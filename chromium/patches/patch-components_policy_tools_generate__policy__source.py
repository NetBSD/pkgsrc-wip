$NetBSD$

--- components/policy/tools/generate_policy_source.py.orig	2020-07-08 21:40:40.000000000 +0000
+++ components/policy/tools/generate_policy_source.py
@@ -38,7 +38,8 @@ PLATFORM_STRINGS = {
     'chrome.win': ['win'],
     'chrome.linux': ['linux'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux'],
+    'chrome.netbsd': ['netbsd'],
+    'chrome.*': ['win', 'mac', 'linux', 'netbsd'],
     'chrome.win7': ['win']
 }
 
@@ -305,7 +306,7 @@ def main():
       '--target-platform',
       dest='target_platform',
       help='the platform the generated code should run on - can be one of'
-      '(win, mac, linux, chromeos, fuchsia)',
+      '(win, mac, linux, chromeos, fuchsia, netbsd)',
       metavar='PLATFORM')
   parser.add_argument(
       '--policy-templates-file',
