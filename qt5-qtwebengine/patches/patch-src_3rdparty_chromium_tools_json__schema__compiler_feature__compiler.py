$NetBSD$

--- src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py
@@ -221,6 +221,8 @@ FEATURE_GRAMMAR = (
           'linux': 'Feature::LINUX_PLATFORM',
           'mac': 'Feature::MACOSX_PLATFORM',
           'win': 'Feature::WIN_PLATFORM',
+          'bsd': 'Feature::LINUX_PLATFORM',
+          'netbsd': 'Feature::LINUX_PLATFORM',
         }
       }
     },
