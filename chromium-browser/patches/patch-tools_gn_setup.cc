$NetBSD$

--- tools/gn/setup.cc.orig	2016-08-05 17:36:04.000000000 +0000
+++ tools/gn/setup.cc
@@ -616,7 +616,7 @@ void Setup::FillPythonPath(const base::C
     }
     build_settings_.set_python_path(python_path.NormalizePathSeparatorsTo('/'));
 #else
-    build_settings_.set_python_path(base::FilePath("python"));
+    build_settings_.set_python_path(base::FilePath("/usr/pkg/bin/python2.7"));
 #endif
   }
 }
