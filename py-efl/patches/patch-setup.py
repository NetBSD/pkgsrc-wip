$NetBSD$

Fix compilation errors looking for ecore-file headers

--- setup.py.orig	2024-05-22 22:58:34.153292852 +0000
+++ setup.py
@@ -202,7 +202,7 @@ if set(('build', 'build_ext', 'install',
         extra_link_args=evas_libs
     ))

-    # === Ecore + EcoreFile ===
+    # === Ecore + EcoreFile ===/./
     ecore_cflags, ecore_libs = pkg_config('Ecore', 'ecore', EFL_MIN_VER)
     ecore_file_cflags, ecore_file_libs = pkg_config('EcoreFile', 'ecore-file', EFL_MIN_VER)
     ext_modules.append(Extension(
@@ -215,7 +215,7 @@ if set(('build', 'build_ext', 'install',
     ecore_input_cflags, ecore_input_libs = pkg_config('EcoreInput', 'ecore-input', EFL_MIN_VER)
     ext_modules.append(Extension(
         'efl.ecore_input', ['efl/ecore_input/efl.ecore_input.' + MODULES_EXT],
-        extra_compile_args=ecore_input_cflags + common_cflags,
+        extra_compile_args=ecore_input_cflags + ecore_file_cflags + common_cflags,
         extra_link_args=ecore_input_libs
     ))

@@ -235,7 +235,7 @@ if set(('build', 'build_ext', 'install',
     else:
         ext_modules.append(Extension(
             'efl.ecore_x', ['efl/ecore_x/efl.ecore_x.' + MODULES_EXT],
-            extra_compile_args=ecore_x_cflags + common_cflags,
+            extra_compile_args=ecore_x_cflags + ecore_file_cflags + common_cflags,
             extra_link_args=ecore_x_libs
         ))
