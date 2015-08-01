$NetBSD: patch-setup.py,v 1.1 2015/08/01 22:33:59 jihbed Exp $

--- setup.py.orig	2015-04-10 00:41:05.000000000 +0000
+++ setup.py
@@ -23,7 +23,6 @@ setup(
     description='CALPHAD tools for designing thermodynamic models, calculating phase diagrams and investigating phase equilibria.',
     packages=['pycalphad', 'pycalphad.eq', 'pycalphad.io', 'pycalphad.plot', 'pycalphad.plot.projections'],
     license='MIT',
-    long_description=read('README.rst'),
     url='https://github.com/richardotis/pycalphad',
     install_requires=['matplotlib', 'pandas', 'sympy', 'pyparsing', 'tinydb', 'scipy', 'numpy'],
     classifiers=[
