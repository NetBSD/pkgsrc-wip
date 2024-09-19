$NetBSD$

--- src/VBox/ValidationKit/testdriver/vboxtestvms.py.orig	2016-03-04 19:30:17.000000000 +0000
+++ src/VBox/ValidationKit/testdriver/vboxtestvms.py
@@ -102,7 +102,8 @@ g_aaNameToDetails = \
     [ 'Solaris',        'Solaris',               g_k32,    1, 256, ['sol10',  'sol10u[0-9]']],
     [ 'Solaris_64',     'Solaris_64',            g_k64,    1, 256, ['sol10-64', 'sol10u-64[0-9]']],
     [ 'Solaris_64',     'Solaris11_64',          g_k64,    1, 256, ['sol11u1']],
-    [ 'BSD',            'FreeBSD_64',            g_k32_64, 1, 1, ['bs-.*']], # boot sectors, wanted 64-bit type.
+    [ 'FreeBSD',        'FreeBSD_64',            g_k32_64, 1, 1, ['bs-.*']], # boot sectors, wanted 64-bit type.
+    [ 'NetBSD',         'NetBSD_64',             g_k32_64, 1, 1, ['bs-.*']], # boot sectors, wanted 64-bit type.
 ];
 
 
@@ -110,6 +111,7 @@ g_aaNameToDetails = \
 ## @{
 g_ksGuestOsTypeDarwin  = 'darwin';
 g_ksGuestOsTypeFreeBSD = 'freebsd';
+g_ksGuestOsTypeNetBSD  = 'netbsd';
 g_ksGuestOsTypeLinux   = 'linux';
 g_ksGuestOsTypeOS2     = 'os2';
 g_ksGuestOsTypeSolaris = 'solaris';
@@ -134,6 +136,7 @@ g_kasParavirtProviders = ( g_ksParavirtP
 #g_kdaParavirtProvidersSupported = {
 #    g_ksGuestOsTypeDarwin  : ( g_ksParavirtProviderMinimal, ),
 #    g_ksGuestOsTypeFreeBSD : ( g_ksParavirtProviderNone, g_ksParavirtProviderMinimal, ),
+#    g_ksGuestOsTypeNetBSD : ( g_ksParavirtProviderNone, g_ksParavirtProviderMinimal, ),
 #    g_ksGuestOsTypeLinux   : ( g_ksParavirtProviderNone, g_ksParavirtProviderMinimal, g_ksParavirtProviderHyperV, g_ksParavirtProviderKVM),
 #    g_ksGuestOsTypeOS2     : ( g_ksParavirtProviderNone, ),
 #    g_ksGuestOsTypeSolaris : ( g_ksParavirtProviderNone, ),
@@ -146,6 +149,7 @@ g_kasParavirtProviders = ( g_ksParavirtP
 g_kdaParavirtProvidersSupported = {
     g_ksGuestOsTypeDarwin  : ( g_ksParavirtProviderMinimal, ),
     g_ksGuestOsTypeFreeBSD : ( g_ksParavirtProviderNone, ),
+    g_ksGuestOsTypeNetBSD : ( g_ksParavirtProviderNone, ),
     g_ksGuestOsTypeLinux   : ( g_ksParavirtProviderNone, g_ksParavirtProviderHyperV, g_ksParavirtProviderKVM),
     g_ksGuestOsTypeOS2     : ( g_ksParavirtProviderNone, ),
     g_ksGuestOsTypeSolaris : ( g_ksParavirtProviderNone, ),
@@ -207,8 +211,10 @@ class TestVm(object):
         """
         if sType.lower().startswith('darwin'):
             return g_ksGuestOsTypeDarwin
-        if sType.lower().startswith('bsd'):
+        if sType.lower().startswith('freebsd'):
             return g_ksGuestOsTypeFreeBSD
+        if sType.lower().startswith('netbsd'):
+            return g_ksGuestOsTypeNetBSD
         if sType.lower().startswith('linux'):
             return g_ksGuestOsTypeLinux
         if sType.lower().startswith('os2'):
@@ -954,4 +960,3 @@ class TestVmManager(object):
     def shutUpPyLint(self):
         """ Shut up already! """
         return self.sResourcePath;
-
