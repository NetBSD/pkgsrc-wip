$NetBSD: patch-BuildTools_SCons_Tools_qt4.py,v 1.1.1.1 2011/07/31 22:28:23 schnoebe Exp $

--- BuildTools/SCons/Tools/qt4.py.orig	2011-04-22 21:07:47.000000000 +0000
+++ BuildTools/SCons/Tools/qt4.py
@@ -445,7 +445,7 @@ def enable_modules(self, modules, debug=
 		except: pass
 	debugSuffix = ''
 
-	if sys.platform in ["linux2"] and not crosscompiling :
+	if sys.platform in ["linux2", "netbsd5", "netbsd6" ] and not crosscompiling :
 		if debug : debugSuffix = '_debug'
 		self.AppendUnique(CPPPATH=[os.path.join("$QTDIR","include", "phonon")])
 		for module in modules :
