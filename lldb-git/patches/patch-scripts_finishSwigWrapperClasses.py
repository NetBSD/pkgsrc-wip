$NetBSD$

--- scripts/finishSwigWrapperClasses.py.orig	2016-09-10 17:36:23.000000000 +0000
+++ scripts/finishSwigWrapperClasses.py
@@ -81,6 +81,7 @@ Args:   -h              (optional) Print
                     created for a Windows build.\n\
     --argsFile=         The args are read from a file instead of the\n\
                     command line. Other command line args are ignored.\n\
+    --useSystemSix  Use system six.py version.\n\
 \n\
 Usage:\n\
     finishSwigWrapperClasses.py --srcRoot=ADirPath --targetDir=ADirPath\n\
@@ -178,7 +179,8 @@ def validate_arguments(vArgv):
         "prefix=",
         "cmakeBuildConfiguration=",
         "lldbLibDir=",
-        "argsFile"]
+        "argsFile",
+        "useSystemSix"]
     dictArgReq = {"-h": "o",          # o = optional, m = mandatory
                   "-d": "o",
                   "-m": "o",
@@ -188,7 +190,8 @@ def validate_arguments(vArgv):
                   "--prefix": "o",
                   "--cmakeBuildConfiguration": "o",
                   "--lldbLibDir": "o",
-                  "--argsFile": "o"}
+                  "--argsFile": "o",
+                  "--useSystemSix": "o"}
 
     # Check for mandatory parameters
     nResult, dictArgs, strMsg = utilsArgsParse.parse(vArgv, strListArgs,
@@ -376,9 +379,11 @@ def main(vArgv):
             (optional)      "lib" by default.
             --argsFile=     The args are read from a file instead of the
                             command line. Other command line args are ignored.
+            --useSystemSix  Use system six.py version.
     Usage:
             finishSwigWrapperClasses.py --srcRoot=ADirPath --targetDir=ADirPath
             --cfgBldDir=ADirPath --prefix=ADirPath --lldbLibDir=ADirPath -m -d
+            --useSystemSix
 
     Results:    0 Success
                 -1 Error - invalid parameters passed.
