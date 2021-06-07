$NetBSD$

On Darwin, set LC_ID_DYLIB to ${PREFIX}/${PYSITELIB}/pysam/...
to ensure libraries are found at runtime.  Avoid use of @rpath.

--- cy_build.py.orig	2018-02-07 21:01:12.000000000 +0000
+++ cy_build.py
@@ -60,20 +60,16 @@ class cy_build_ext(build_ext):
             ext.library_dirs.append(os.path.join(self.build_lib, "pysam"))
 
         if sys.platform == 'darwin':
-            # The idea is to give shared libraries an install name of the form
-            # `@rpath/<library-name.so>`, and to set the rpath equal to
-            # @loader_path. This will allow Python packages to find the library
-            # in the expected place, while still giving enough flexibility to
-            # external applications to link against the library.
+            # Set LC_ID_DYLIB to ${PREFIX}/${PYSITELIB}/pysam/... to ensure
+            # libraries are found at runtime.  Avoid use of @rpath.
             relative_module_path = ext.name.replace(".", os.sep) + get_config_vars()["SO"]
             library_path = os.path.join(
-                "@rpath", os.path.basename(relative_module_path)
+                os.environ["PREFIX"], os.environ["PYSITELIB"], "pysam", os.path.basename(relative_module_path)
             )
 
             if not ext.extra_link_args:
                 ext.extra_link_args = []
             ext.extra_link_args += ['-dynamiclib',
-                                    '-rpath', '@loader_path',
                                     '-Wl,-headerpad_max_install_names',
                                     '-Wl,-install_name,%s' % library_path,
                                     '-Wl,-x']
