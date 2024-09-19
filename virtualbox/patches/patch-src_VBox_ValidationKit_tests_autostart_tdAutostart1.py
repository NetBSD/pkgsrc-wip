$NetBSD$

--- src/VBox/ValidationKit/tests/autostart/tdAutostart1.py.orig	2016-03-04 19:30:19.000000000 +0000
+++ src/VBox/ValidationKit/tests/autostart/tdAutostart1.py
@@ -461,6 +461,7 @@ class tdAutostart(vbox.TestDriver):     
     ksOsDarwin  = 'tst-darwin'
     ksOsSolaris = 'tst-solaris'
     ksOsFreeBSD = 'tst-freebsd'
+    ksOsNetBSD = 'tst-netbsd'
 
     def __init__(self):
         vbox.TestDriver.__init__(self);
@@ -703,4 +704,3 @@ class tdAutostart(vbox.TestDriver):     
 
 if __name__ == '__main__':
     sys.exit(tdAutostart().main(sys.argv));
-
