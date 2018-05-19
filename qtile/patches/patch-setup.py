$NetBSD$

Install man pages to the right place.

--- setup.py.orig	2018-03-01 13:31:23.000000000 +0000
+++ setup.py
@@ -153,7 +153,7 @@ setup(
         'bin/dqcmd',
     ],
     data_files=[
-        ('share/man/man1', ['resources/qtile.1',
+        ('man/man1',       ['resources/qtile.1',
                             'resources/qshell.1'])],
     cmdclass={'install': CheckCairoXcb},
     cffi_modules=[
