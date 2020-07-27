$NetBSD$

--- tools/json_schema_compiler/feature_compiler.py.orig	2020-07-15 18:56:33.000000000 +0000
+++ tools/json_schema_compiler/feature_compiler.py
@@ -238,6 +238,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
+                'netbsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
