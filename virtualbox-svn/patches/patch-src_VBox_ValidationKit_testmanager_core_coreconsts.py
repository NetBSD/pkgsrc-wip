$NetBSD$

--- src/VBox/ValidationKit/testmanager/core/coreconsts.py.orig	2016-03-04 19:30:17.000000000 +0000
+++ src/VBox/ValidationKit/testmanager/core/coreconsts.py
@@ -33,5 +33,5 @@ g_ksOsAgnostic      = 'os-agnostic';
 ## All known OSes, except the agnostic one.
 # See KBUILD_OSES in kBuild/header.kmk for reference.
-g_kasOses           = ['darwin', 'dos', 'dragonfly', 'freebsd', 'haiku', 'l4', 'linux', 'netbsd', 'nt', 'openbsd', 'os2',
+g_kasOses           = ['darwin', 'dos', 'dragonfly', 'freebsd', 'netbsd', 'haiku', 'l4', 'linux', 'netbsd', 'nt', 'openbsd', 'os2',
                        'solaris', 'win'];
 ## All known OSes, including the agnostic one.
@@ -65,4 +65,5 @@ g_kasOsDotCpus = \
     'freebsd.amd64', 'freebsd.x86', 'freebsd.sparc64', 'freebsd.ia64', 'freebsd.ppc32', 'freebsd.ppc64', 'freebsd.arm',
     'freebsd.mips32', 'freebsd.mips64',
+    'netbsd.amd64', 'netbsd.x86',
     'haiku.amd64', 'haiku.x86',
     'l4.amd64', 'l4.x86', 'l4.ppc32', 'l4.ppc64', 'l4.arm',
@@ -73,5 +74,5 @@ g_kasOsDotCpus = \
 ];
 for sOs in g_kasOses:
-    if sOs not in ['darwin', 'dos', 'dragonfly', 'freebsd', 'haiku', 'l4', 'nt', 'win', 'os2', 'solaris']:
+    if sOs not in ['darwin', 'dos', 'dragonfly', 'freebsd', 'netbsd', 'haiku', 'l4', 'nt', 'win', 'os2', 'solaris']:
         for sArch in g_kasCpuArches:
             g_kasOsDotCpus.append(sOs + '.' + sArch);
@@ -86,3 +87,2 @@ for sArch in g_kasCpuArchesAll:
     g_kasOsDotCpusAll.append(g_ksOsAgnostic + '.' + sArch);
 g_kasOsDotCpusAll.sort();
-
