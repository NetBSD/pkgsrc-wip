$NetBSD: patch-BuildTools_SCons_SConscript.boot,v 1.1 2014/12/12 10:50:49 joerg Exp $

Don't strip environment so pkgsrc settings survive.

--- BuildTools/SCons/SConscript.boot.orig	2015-07-22 14:04:23.000000000 +0000
+++ BuildTools/SCons/SConscript.boot
@@ -106,11 +106,7 @@ vars.Add(BoolVariable("install_git_hooks
 # Set up default build & configure environment
 ################################################################################
 
-env_ENV = {
-	'PATH' : os.environ['PATH'],
-	'LD_LIBRARY_PATH' : os.environ.get("LD_LIBRARY_PATH", ""),
-	'TERM' : os.environ.get("TERM", ""),
-}
+env_ENV = os.environ
 
 if "MSVC_VERSION" in ARGUMENTS :
 	env = Environment(ENV = env_ENV, variables = vars, MSVC_VERSION = ARGUMENTS["MSVC_VERSION"], platform = ARGUMENTS.get("PLATFORM", None))
