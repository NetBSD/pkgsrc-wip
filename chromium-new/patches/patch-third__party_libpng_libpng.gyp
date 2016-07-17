$NetBSD$

--- third_party/libpng/libpng.gyp.orig	2016-07-11 12:43:07.907561444 +0000
+++ third_party/libpng/libpng.gyp
@@ -1,4 +1,4 @@
-# Copyright (c) 2012 The Chromium Authors. All rights reserved.
+# Copyright 2013 The Chromium Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
@@ -6,89 +6,33 @@
   'targets': [
     {
       'target_name': 'libpng',
+      'type': 'none',
       'dependencies': [
         '../zlib/zlib.gyp:zlib',
       ],
-      'variables': {
-        # Upstream uses self-assignment to avoid warnings.
-        'clang_warning_flags': [ '-Wno-self-assign' ]
-      },
-      'defines': [
-        'CHROME_PNG_WRITE_SUPPORT',
-        'PNG_USER_CONFIG',
-      ],
-      'sources': [
-        'png.c',
-        'png.h',
-        'pngconf.h',
-        'pngerror.c',
-        'pnggccrd.c',
-        'pngget.c',
-        'pngmem.c',
-        'pngpread.c',
-        'pngread.c',
-        'pngrio.c',
-        'pngrtran.c',
-        'pngrutil.c',
-        'pngset.c',
-        'pngtrans.c',
-        'pngusr.h',
-        'pngvcrd.c',
-        'pngwio.c',
-        'pngwrite.c',
-        'pngwtran.c',
-        'pngwutil.c',
-      ],
       'direct_dependent_settings': {
-        'include_dirs': [
-          '.',
+        'cflags': [
+          '<!@(pkg-config --cflags libpng)',
+        ],
+      },
+      'link_settings': {
+        'ldflags': [
+          '<!@(pkg-config --libs-only-L --libs-only-other libpng)',
         ],
-        'defines': [
-          'CHROME_PNG_WRITE_SUPPORT',
-          'PNG_USER_CONFIG',
+        'libraries': [
+          '<!@(pkg-config --libs-only-l libpng)',
         ],
       },
-      'export_dependent_settings': [
-        '../zlib/zlib.gyp:zlib',
-      ],
-      # TODO(jschuh): http://crbug.com/167187
-      'msvs_disabled_warnings': [ 4267 ],
-      'conditions': [
-        ['OS!="win"', {'product_name': 'png'}],
-        ['OS=="win"', {
-          'type': '<(component)',
-        }, {
-          # Chromium libpng does not support building as a shared_library
-          # on non-Windows platforms.
-          'type': 'static_library',
-        }],
-        ['OS=="win" and component=="shared_library"', {
-          'defines': [
-            'PNG_BUILD_DLL',
-            'PNG_NO_MODULEDEF',
-          ],
-          'direct_dependent_settings': {
-            'defines': [
-              'PNG_USE_DLL',
-            ],
-          },
-        }],
-        ['OS=="android" or chromecast==1', {
-          'conditions': [
-            ['OS=="android"', {
-              'toolsets': ['target', 'host'],
-            }],
-          ],
-          'defines': [
-            'CHROME_PNG_READ_PACK_SUPPORT',  # Required by freetype.
-          ],
-          'direct_dependent_settings': {
-            'defines': [
-              'CHROME_PNG_READ_PACK_SUPPORT',
-            ],
-          },
-        }],
+      'variables': {
+        'headers_root_path': '.',
+        'header_filenames': [
+          'png.h',
+          'pngconf.h',
+        ],
+      },
+      'includes': [
+        '../../build/shim_headers.gypi',
       ],
     },
-  ]
+  ],
 }
