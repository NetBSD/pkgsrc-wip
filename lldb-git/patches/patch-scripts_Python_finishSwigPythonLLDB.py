$NetBSD$

--- scripts/Python/finishSwigPythonLLDB.py.orig	2016-12-14 14:10:24.000000000 +0000
+++ scripts/Python/finishSwigPythonLLDB.py
@@ -821,7 +821,9 @@ def main(vDictArgs):
         bOk, strMsg = create_symlinks(
             vDictArgs, strFrameworkPythonDir, strLldbLibDir)
 
-    if bOk:
+    bUseSystemSix = "--useSystemSix" in vDictArgs
+
+    if not bUseSystemSix and bOk:
         bOk, strMsg = copy_six(vDictArgs, strFrameworkPythonDir)
 
     if bOk:
