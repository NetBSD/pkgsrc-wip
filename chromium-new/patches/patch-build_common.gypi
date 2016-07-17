$NetBSD$

--- build/common.gypi.orig	2016-06-24 01:02:09.000000000 +0000
+++ build/common.gypi
@@ -113,7 +113,7 @@
 
           'conditions': [
             # Windows and Linux use Aura, but not Ash.
-            ['OS=="win" or OS=="linux"', {
+            ['OS=="win" or OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd"', {
               'use_aura%': 1,
             }],
 
@@ -138,7 +138,7 @@
             }],
 
             # Whether we're a traditional desktop unix.
-            ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris") and chromeos==0', {
+            ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd" or OS=="solaris") and chromeos==0', {
               'desktop_linux%': 1,
             }, {
               'desktop_linux%': 0,
@@ -255,13 +255,13 @@
           }],
 
           # Enable HiDPI on Mac OS, Windows and Linux (including Chrome OS).
-          ['OS=="mac" or OS=="win" or OS=="linux"', {
+          ['OS=="mac" or OS=="win" or OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd"', {
             'enable_hidpi%': 1,
           }],
 
           # Enable Top Chrome Material Design on Chrome OS, Windows, and Linux,
           # and Mac.
-          ['chromeos==1 or OS=="win" or OS=="linux" or OS=="mac"', {
+          ['chromeos==1 or OS=="win" or OS=="linux" or OS=="mac" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd"', {
             'enable_topchrome_md%': 1,
           }],
 
@@ -730,14 +730,20 @@
         }],
 
         # A flag for BSD platforms
-        ['OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="freebsd" or OS=="openbsd" or OS=="netbsd"', {
           'os_bsd%': 1,
         }, {
           'os_bsd%': 0,
         }],
 
+        ['OS=="freebsd" or OS=="openbsd" or OS=="netbsd"', {
+            'icu_use_data_file_flag%': 0,
+        }, {
+            'icu_use_data_file_flag%': 1,
+        }],
+
         # NSS usage.
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris")', {
+        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd" or OS=="solaris")', {
           'use_nss_certs%': 1,
         }, {
           'use_nss_certs%': 0,
@@ -746,7 +752,7 @@
         # NSS verifier usage.
         # On non-OpenSSL iOS configurations, certificates use the operating
         # system library, but the verifier uses the bundled copy of NSS.
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris") or (OS=="ios" and use_openssl==0)', {
+        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd" or OS=="solaris") or (OS=="ios" and use_openssl==0)', {
           'use_nss_verifier%': 1,
         }, {
           'use_nss_verifier%': 0,
@@ -790,7 +796,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd" or OS=="netbsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -892,7 +898,7 @@
 
         # Use GPU accelerated cross process image transport by default
         # on linux builds with the Aura window manager
-        ['use_aura==1 and OS=="linux"', {
+        ['use_aura==1 and (OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd")', {
           'ui_compositor_image_transport%': 1,
         }, {
           'ui_compositor_image_transport%': 0,
@@ -1021,7 +1027,7 @@
         }, {
           'use_openmax_dl_fft%': 0,
         }],
-        ['OS=="win" or OS=="linux"', {
+        ['OS=="win" or OS=="linux" or OS=="freebsd"', {
           'enable_mdns%' : 1,
         }],
 
@@ -1321,6 +1327,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    # XXX(rene) More options, keep them?
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -4724,6 +4734,24 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie'
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
+      },
+    }],
+    # NetBSD
+    ['OS=="netbsd"', {
+      'target_defaults': {
+        'ldflags!': [
+          '-ldl',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
@@ -5240,7 +5268,7 @@
           # 2. Further down, library_dirs is set to
           #    third_party/libc++-static, which contains a static
           #    libc++.a library.  The linker then links against that instead
-          #    of against /usr/lib/libc++.dylib when it sees the -lc++ flag
+          #    of against /usr/tmp/pkgsrc/wip/chromium-new/work/.buildlink/lib/libc++.dylib when it sees the -lc++ flag
           #    added by the driver.
           #
           # In component builds, just link to the system libc++.  This has
