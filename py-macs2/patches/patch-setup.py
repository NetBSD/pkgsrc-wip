$NetBSD$

# Remove lexical version comparison

--- setup.py.orig	2023-01-19 15:12:37.871351424 +0000
+++ setup.py
@@ -20,10 +20,6 @@ numpy_requires = '>=1.17'
 install_requires = [f"numpy>={numpy_requires}",]
 
 def main():
-    if float(sys.version[:3])<3.6:
-        sys.stderr.write("CRITICAL: Python version must >= 3.6!\n")
-        sys.exit(1)
-
     cwd = os.path.abspath(os.path.dirname(__file__))
 
     # install required numpy
