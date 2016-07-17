$NetBSD$

--- components/policy/tools/generate_policy_source.py.orig	2016-06-24 01:02:19.000000000 +0000
+++ components/policy/tools/generate_policy_source.py
@@ -102,7 +102,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'freebsd', 'netbsd'])
         else:
           self.platforms.append(platform_sub)
       else:
