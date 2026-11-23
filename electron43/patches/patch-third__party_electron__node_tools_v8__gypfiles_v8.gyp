$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/tools/v8_gypfiles/v8.gyp.orig	2026-11-23 18:17:12.736865894 +0000
+++ third_party/electron_node/tools/v8_gypfiles/v8.gyp
@@ -762,7 +762,7 @@
               }],
               ['v8_enable_webassembly==1', {
                 'conditions': [
-                  ['OS in "linux mac ios freebsd openharmony"', {
+                  ['OS in "linux mac ios freebsd openbsd netbsd openharmony"', {
                     'sources': [
                       '<(V8_ROOT)/src/trap-handler/handler-inside-posix.h',
                     ],
@@ -1195,7 +1195,7 @@
             }],
             ['v8_enable_webassembly==1', {
               'conditions': [
-                ['OS in "linux mac ios freebsd openharmony"', {
+                ['OS in "linux mac ios freebsd openbsd netbsd openharmony"', {
                   'sources': [
                     '<(V8_ROOT)/src/trap-handler/handler-inside-posix.cc',
                     '<(V8_ROOT)/src/trap-handler/handler-outside-posix.cc',
@@ -1365,6 +1365,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access.
+        # NetBSD/arm also needs -larm.
+        ['OS=="netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         # Clang needs it for some atomic operations (https://clang.llvm.org/docs/Toolchain.html#atomics-library).
         ['(OS=="linux" and clang==1) or (v8_current_cpu in ["mips64", "mips64el", "arm", "riscv64", "loong64"])', {
           'link_settings': {
