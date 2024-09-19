$NetBSD$

Don't strip environment so pkgsrc settings survive.

--- BuildTools/SCons/SConscript.boot.orig	2016-07-20 22:17:03.000000000 +0000
+++ BuildTools/SCons/SConscript.boot
@@ -110,11 +110,7 @@ vars.Add("codesign_identity", "macOS cod
 # Set up default build & configure environment
 ################################################################################
 
-env_ENV = {
-    'PATH' : os.environ['PATH'],
-    'LD_LIBRARY_PATH' : os.environ.get("LD_LIBRARY_PATH", ""),
-    'TERM' : os.environ.get("TERM", ""),
-}
+env_ENV = os.environ
 
 if "MSVC_VERSION" in ARGUMENTS :
     env = Environment(ENV = env_ENV, variables = vars, MSVC_VERSION = ARGUMENTS["MSVC_VERSION"], platform = ARGUMENTS.get("PLATFORM", None))
