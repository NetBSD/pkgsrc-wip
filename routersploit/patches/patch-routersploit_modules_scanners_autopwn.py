$NetBSD$

- Use MODULES_DIR instead of picking up modules in ${PWD} (and mostly likely
  failing)

Patch shared upstream via:

 <https://github.com/threat9/routersploit/pull/578>

--- routersploit/modules/scanners/autopwn.py.orig	2018-10-17 17:30:53.000000000 +0000
+++ routersploit/modules/scanners/autopwn.py
@@ -34,8 +34,8 @@ class Exploit(Exploit):
         self.vulnerabilities = []
         self.creds = []
         self.not_verified = []
-        self._exploits_directories = [path.join("routersploit/modules/exploits/", module) for module in self.modules]
-        self._creds_directories = [path.join("routersploit/modules/creds/", module) for module in self.modules]
+        self._exploits_directories = [path.join(utils.MODULES_DIR, "exploits", module) for module in self.modules]
+        self._creds_directories = [path.join(utils.MODULES_DIR, "creds", module) for module in self.modules]
 
     def run(self):
         self.vulnerabilities = []
