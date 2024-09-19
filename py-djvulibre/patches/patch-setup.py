$NetBSD$

Skip (broken-in-pkgsrc) cython detection.
pkgsrc will supply a sufficient cython.

--- setup.py.orig	2016-08-03 17:57:43.000000000 +0000
+++ setup.py
@@ -164,7 +164,7 @@ def get_cython_version():
     return distutils.version.LooseVersion(ver)
 
 py_version = get_version()
-cython_version = get_cython_version()
+cython_version = "0.20"
 if str != bytes:
     # Python 3.X
     req_cython_version = '0.20'
@@ -222,8 +222,6 @@ class build_ext(distutils.command.build_
                 continue
             distutils.log.info('cythoning {ext.name!r} extension'.format(ext=ext))
             def build_c(source, target):
-                if cython_version < req_cython_version:
-                    raise RuntimeError('Cython >= {ver} is required'.format(ver=req_cython_version))
                 distutils.spawn.spawn([
                     'python', '-m', 'cython',
                     '-I', os.path.dirname(self.config_path),
@@ -290,7 +288,7 @@ if __name__ == '__main__':
         # We wouldn't normally want setuptools; but pip forces it upon us anyway,
         # so let's abuse it to instruct pip to install Cython if it's missing.
         distutils.core.setup(
-            install_requires=['Cython>={ver}'.format(ver=req_cython_version)],
+            install_requires=[],
             # Conceptually, “setup_requires” would make more sense than
             # “install_requires”, but the former is not supported by pip:
             # https://github.com/pypa/pip/issues/1820
