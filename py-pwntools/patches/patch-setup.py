$NetBSD$

- Avoid to needs and call pandoc to convert description

--- setup.py.orig	2021-07-12 21:07:26.000000000 +0000
+++ setup.py
@@ -76,14 +76,6 @@ if not os.path.exists(PythonH):
     print("$ apt-get install python-dev", file=sys.stderr)
     sys.exit(-1)
 
-# Convert README.md to reStructuredText for PyPI
-long_description = ''
-try:
-    long_description = subprocess.check_output(['pandoc', 'README.md', '--to=rst'], universal_newlines=True)
-except Exception as e:
-    print("Failed to convert README.md through pandoc, proceeding anyway", file=sys.stderr)
-    traceback.print_exc()
-
 setup(
     name                 = 'pwntools',
     python_requires      = '>=2.7',
@@ -105,7 +97,6 @@ setup(
     entry_points = {'console_scripts': console_scripts},
     scripts              = glob.glob("bin/*"),
     description          = "Pwntools CTF framework and exploit development library.",
-    long_description     = long_description,
     author               = "Gallopsled et al.",
     author_email         = "pwntools-users@googlegroups.com",
     url                  = 'https://pwntools.com',
