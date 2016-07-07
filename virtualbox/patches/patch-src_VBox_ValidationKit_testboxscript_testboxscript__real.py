$NetBSD$

--- src/VBox/ValidationKit/testboxscript/testboxscript_real.py.orig	2016-03-04 19:30:17.000000000 +0000
+++ src/VBox/ValidationKit/testboxscript/testboxscript_real.py
@@ -267,7 +267,7 @@ class TestBoxScript(object):
         # Platform specific mount code.
         #
         sHostOs = utils.getHostOs()
-        if sHostOs in ('darwin', 'freebsd'):
+        if sHostOs in ('darwin', 'freebsd', 'netbsd'):
             utils.sudoProcessCall(['/sbin/umount', sMountPoint]);
             utils.sudoProcessCall(['/bin/mkdir', '-p', sMountPoint]);
             utils.sudoProcessCall(['/usr/sbin/chown', str(os.getuid()), sMountPoint]); # pylint: disable=E1101
@@ -996,4 +996,3 @@ class TestBoxScript(object):
 
 if __name__ == '__main__':
     sys.exit(TestBoxScript.main());
-
