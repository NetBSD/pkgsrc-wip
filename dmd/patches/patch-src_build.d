$NetBSD$

--- src/build.d.orig	2020-08-15 09:49:13.000000000 +0000
+++ src/build.d
@@ -753,16 +753,14 @@ alias install = makeRule!((builder, rule
                 const bin = "bin" ~ env["MODEL"];
         }
 
-        installRelativeFiles(env["INSTALL"].buildPath(env["OS"], bin), dmdExeFile.dirName, dmdExeFile.only, octal!755);
+        installRelativeFiles(env["INSTALL"].buildPath(bin), dmdExeFile.dirName, dmdExeFile.only, octal!755);
 
         version (Windows)
             installRelativeFiles(env["INSTALL"], dmdRepo, sourceFiles);
 
         const scPath = buildPath(env["OS"], bin, conf);
-        copyAndTouch(buildPath(dmdRepo, "ini", scPath), buildPath(env["INSTALL"], scPath));
-
-        version (Posix)
-            copyAndTouch(sourceFiles[$-1], env["INSTALL"].buildPath("dmd-boostlicense.txt"));
+	mkdirRecurse(buildPath(env["INSTALL"], "etc"));
+        copyAndTouch(buildPath(dmdRepo, "ini", scPath), buildPath(env["INSTALL"], "etc", conf));
 
     });
 });
