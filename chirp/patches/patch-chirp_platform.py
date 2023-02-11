$NetBSD: patch-chirp_platform.py,v 1.2 2020/08/25 13:45:53 gdt Exp $

Don't look for share other than in the right place.
\todo File upstream.
\todo Make upstream respect a configured share dir.

Excise Darwin hack that works around misconfigured systems.
\todo Discuss upstream.

--- chirp/platform.py.orig	2022-12-15 10:00:29.000000000 +0000
+++ chirp/platform.py
@@ -252,10 +252,7 @@ class Platform:
         """Searches for files installed to a share/ prefix."""
         execpath = self.executable_path()
         share_candidates = [
-            os.path.join(execpath, "share"),
             os.path.join(sys.prefix, "share"),
-            "/usr/local/share",
-            "/usr/share",
         ]
         pkgshare_candidates = [os.path.join(i, "chirp")
                                for i in share_candidates]
@@ -287,16 +284,6 @@ class UnixPlatform(Platform):
 
         Platform.__init__(self, str(basepath))
 
-        # This is a hack that needs to be properly fixed by importing the
-        # latest changes to this module from d-rats.  In the interest of
-        # time, however, I'll throw it here
-        if sys.platform == "darwin":
-            if "DISPLAY" not in os.environ:
-                LOG.info("Forcing DISPLAY for MacOS")
-                os.environ["DISPLAY"] = ":0"
-
-            os.environ["PANGO_RC_FILE"] = "../Resources/etc/pango/pangorc"
-
     def default_dir(self):
         return str(Path.home())
 
