$NetBSD$

--- src/VBox/ValidationKit/testdriver/base.py.orig	2016-03-04 19:30:17.000000000 +0000
+++ src/VBox/ValidationKit/testdriver/base.py
@@ -827,6 +827,7 @@ class TestDriverBase(object): # pylint: 
         if self.sResourcePath is None:
             if self.sHost == 'darwin':      self.sResourcePath = "/Volumes/testrsrc/";
             elif self.sHost == 'freebsd':   self.sResourcePath = "/mnt/testrsrc/";
+            elif self.sHost == 'netbsd':   self.sResourcePath = "/mnt/testrsrc/";
             elif self.sHost == 'linux':     self.sResourcePath = "/mnt/testrsrc/";
             elif self.sHost == 'os2':       self.sResourcePath = "T:/";
             elif self.sHost == 'solaris':   self.sResourcePath = "/mnt/testrsrc/";
@@ -1719,4 +1720,3 @@ class TestDriverBaseTestCase(unittest.Te
 if __name__ == '__main__':
     unittest.main();
     # not reached.
-
