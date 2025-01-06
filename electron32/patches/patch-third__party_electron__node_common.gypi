$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/common.gypi.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/common.gypi
@@ -86,8 +86,27 @@
     'v8_use_perfetto': 0,
     'tsan%': 0,
 
+    'using_electron_config_gypi%': 0,
+
     ##### end V8 defaults #####
 
+    # When building native modules using 'npm install' with the system npm,
+    # node-gyp uses the `process.config` of the system npm to fill config.gypi.
+    # If the system npm is not as recent as Electron's node headers, which is
+    # likely, these variables will be missing from that config.gypi, and as a
+    # result, node-gyp will fail when building the native module with an error
+    # like:
+    #
+    #  gyp: name 'enable_lto' is not defined while evaluating condition
+    #  'enable_lto=="true"' in binding.gyp while trying to load binding.gyp
+    #
+    # We set default values here to avoid that error message, even though these
+    # aren't technically accurate, because most native modules don't depend on
+    # these values being accurate.
+    'build_v8_with_gn': 'false',
+    'enable_lto%': 'false',
+    'llvm_version': '0.0',
+
     'conditions': [
       ['OS == "win"', {
         'os_posix': 0,
@@ -106,6 +125,7 @@
         'v8_base': '<(PRODUCT_DIR)/obj.target/tools/v8_gypfiles/libv8_snapshot.a',
       }],
       ['OS=="mac"', {
+        'clang%': 1,
         'obj_dir%': '<(PRODUCT_DIR)/obj.target',
         'v8_base': '<(PRODUCT_DIR)/libv8_snapshot.a',
       }],
@@ -268,6 +288,7 @@
     # Defines these mostly for node-gyp to pickup.
     'defines': [
       '_GLIBCXX_USE_CXX11_ABI=1',
+      'ELECTRON_ENSURE_CONFIG_GYPI',
     ],
 
     # Forcibly disable -Werror.  We support a wide range of compilers, it's
@@ -285,7 +306,7 @@
       'VCCLCompilerTool': {
         'AdditionalOptions': [
           '/Zc:__cplusplus',
-          '-std:c++17'
+          '-std:c++20'
         ],
         'BufferSecurityCheck': 'true',
         'DebugInformationFormat': 1,          # /Z7 embed info in .obj files
@@ -397,6 +418,11 @@
           }],
         ],
       }],
+      ['using_electron_config_gypi == 1', {
+        'defines': [
+          'USING_ELECTRON_CONFIG_GYPI',
+        ],
+      }],
       # The defines bellow must include all things from the external_v8_defines
       # list in v8/BUILD.gn.
       ['v8_enable_v8_checks == 1', {
@@ -462,7 +488,7 @@
       }],
       [ 'OS in "linux freebsd openbsd solaris android aix os400 cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
-        'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++17' ],
+        'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++20' ],
         'defines': [ '__STDC_FORMAT_MACROS' ],
         'ldflags': [ '-rdynamic' ],
         'target_conditions': [
@@ -633,7 +659,7 @@
           ['clang==1', {
             'xcode_settings': {
               'GCC_VERSION': 'com.apple.compilers.llvm.clang.1_0',
-              'CLANG_CXX_LANGUAGE_STANDARD': 'gnu++17',  # -std=gnu++17
+              'CLANG_CXX_LANGUAGE_STANDARD': 'gnu++20',  # -std=gnu++20
               'CLANG_CXX_LIBRARY': 'libc++',
             },
           }],
