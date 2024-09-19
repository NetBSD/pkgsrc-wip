$NetBSD: patch-setup.py,v 1.1 2014/07/25 22:00:58 jihbed Exp $

--- setup.py.orig	2010-06-12 18:50:52.000000000 +0000
+++ setup.py	2010-06-20 01:14:17.000000000 +0000
@@ -6,8 +6,10 @@
 # to install type: 
 # python setup.py install --root=/
 
+data_files = [ ]
 locales=map(lambda i: ('share/'+i,[''+i+'/othman.mo',]),glob('locale/*/LC_MESSAGES'))
-data_files=[('share/othman/',glob('othman-data/*'))]
+data_files.append(('share/othman/',glob('othman-data/*')))
+data_files.append(('/usr/pkg/share/applications',['./Othman.desktop.in']))
 data_files.extend(locales)
 setup (name='Othman', version='0.2.2',
       description='Othman Quran Browser',
