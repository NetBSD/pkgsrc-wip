$NetBSD$

--- components/policy/tools/generate_policy_source.py.orig	2017-02-02 02:02:52.000000000 +0000
+++ components/policy/tools/generate_policy_source.py
@@ -102,7 +102,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'netbsd'])
         else:
           self.platforms.append(platform_sub)
       else:
