$NetBSD$

--- scripts/Python/finishSwigPythonLLDB.py.orig	2016-12-14 14:10:24.000000000 +0000
+++ scripts/Python/finishSwigPythonLLDB.py
@@ -70,7 +70,6 @@ strErrMsgCreatePyPkgMissingSlash = "Para
 strErrMsgMkLinkExecute = "Command mklink failed: %s"
 strErrMsgMakeSymlink = "creating symbolic link"
 strErrMsgUnexpected = "Unexpected error: %s"
-strMsgCopySixPy = "Copying six.py from '%s' to '%s'"
 strErrMsgCopySixPyFailed = "Unable to copy '%s' to '%s'"
 
 
@@ -527,33 +526,6 @@ def create_symlinks(vDictArgs, vstrFrame
     return (bOk, strErrMsg)
 
 
-def copy_six(vDictArgs, vstrFrameworkPythonDir):
-    dbg = utilsDebug.CDebugFnVerbose("Python script copy_six()")
-    bDbg = "-d" in vDictArgs
-    bOk = True
-    strMsg = ""
-    site_packages_dir = os.path.dirname(vstrFrameworkPythonDir)
-    six_module_filename = "six.py"
-    src_file = os.path.join(
-        vDictArgs['--srcRoot'],
-        "third_party",
-        "Python",
-        "module",
-        "six",
-        six_module_filename)
-    src_file = os.path.normpath(src_file)
-    target = os.path.join(site_packages_dir, six_module_filename)
-
-    if bDbg:
-        print((strMsgCopySixPy % (src_file, target)))
-    try:
-        shutil.copyfile(src_file, target)
-    except:
-        bOk = False
-        strMsg = strErrMsgCopySixPyFailed % (src_file, target)
-
-    return (bOk, strMsg)
-
 #++---------------------------------------------------------------------------
 # Details:  Look for the directory in which to put the Python files if it
 #           does not already exist, attempt to make it.
@@ -822,9 +794,6 @@ def main(vDictArgs):
             vDictArgs, strFrameworkPythonDir, strLldbLibDir)
 
     if bOk:
-        bOk, strMsg = copy_six(vDictArgs, strFrameworkPythonDir)
-
-    if bOk:
         bOk, strMsg = copy_lldbpy_file_to_lldb_pkg_dir(vDictArgs,
                                                        strFrameworkPythonDir,
                                                        strCfgBldDir)
