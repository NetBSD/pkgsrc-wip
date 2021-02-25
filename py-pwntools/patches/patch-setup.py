$NetBSD$

Relax version requirements.

--- setup.py.orig	2020-11-29 23:44:02.000000000 +0000
+++ setup.py
@@ -60,7 +60,7 @@ install_requires     = ['paramiko>=1.15.
                         'psutil>=3.3.0',
                         'intervaltree>=3.0',
                         'sortedcontainers',
-                        'unicorn>=1.0.2rc1,<1.0.2rc4', # see unicorn-engine/unicorn#1100, unicorn-engine/unicorn#1170, Gallopsled/pwntools#1538
+                        'unicorn>=1.0.2rc1', # see unicorn-engine/unicorn#1100, unicorn-engine/unicorn#1170, Gallopsled/pwntools#1538
                         'six>=1.12.0',
 ]
 
