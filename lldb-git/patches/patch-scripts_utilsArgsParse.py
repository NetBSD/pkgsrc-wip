$NetBSD$

--- scripts/utilsArgsParse.py.orig	2016-09-10 17:36:23.000000000 +0000
+++ scripts/utilsArgsParse.py
@@ -113,12 +113,12 @@ def parse(vArgv, vstrListArgs, vListLong
                 break
         if match == 0:
             for arg in vListLongArgs:
-                argg = "--" + arg[:arg.__len__() - 1]
+                argg = "--" + arg.rstrip('=')
                 if opt == argg:
                     if "m" == vDictArgReq[opt]:
                         countMandatoryOpts = countMandatoryOpts + 1
                     dictArgs[opt] = val
-                    if val.__len__() == 0:
+                    if arg[-1:] == '=' and val.__len__() == 0:
                         bFoundNoInputValue = True
                     break
 
