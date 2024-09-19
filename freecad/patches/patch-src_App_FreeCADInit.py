$NetBSD$

/lib and /bin are not under the home path

--- src/App/FreeCADInit.py.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/App/FreeCADInit.py
@@ -43,11 +43,11 @@ def InitApplications():
 	# Checking on FreeCAD module path ++++++++++++++++++++++++++++++++++++++++++
 	ModDir = FreeCAD.getHomePath()+'Mod'
 	ModDir = os.path.realpath(ModDir)
-	BinDir = FreeCAD.getHomePath()+'bin'
+	BinDir = FreeCAD.getHomePath()+'../bin'
 	BinDir = os.path.realpath(BinDir)
-	LibDir = FreeCAD.getHomePath()+'lib'
+	LibDir = FreeCAD.getHomePath()+'../lib'
 	LibDir = os.path.realpath(LibDir)
-	Lib64Dir = FreeCAD.getHomePath()+'lib64'
+	Lib64Dir = FreeCAD.getHomePath()+'../lib64'
 	Lib64Dir = os.path.realpath(Lib64Dir)
 	AddPath = FreeCAD.ConfigGet("AdditionalModulePaths").split(";")
 	HomeMod = FreeCAD.ConfigGet("UserAppData")+"Mod"
