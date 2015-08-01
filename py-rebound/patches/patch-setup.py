$NetBSD: patch-setup.py,v 1.1 2015/08/01 22:31:16 jihbed Exp $

--- setup.py.orig	2015-07-30 16:44:56.000000000 +0000
+++ setup.py
@@ -25,7 +25,7 @@ libreboundmodule = Extension('librebound
                                 ],
                     include_dirs = ['src'],
                     define_macros=[ ('LIBREBOUND', None) ],
-                    extra_compile_args=['-fstrict-aliasing', '-O3','-std=c99','-march=native','-Wno-unknown-pragmas', '-DLIBREBOUND', '-D_GNU_SOURCE', '-fPIC'],
+                    extra_compile_args=['-fstrict-aliasing', '-O3','-std=c99','-Wno-unknown-pragmas', '-DLIBREBOUND', '-D_GNU_SOURCE', '-fPIC'],
                                     )
 
 here = os.path.abspath(os.path.dirname(__file__))
