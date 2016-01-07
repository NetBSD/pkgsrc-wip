$NetBSD$

Fix build with strict aliasing turned on.
http://xpra.org/trac/ticket/1080

--- setup.py.orig	2015-12-27 17:19:18.000000000 +0000
+++ setup.py
@@ -619,6 +619,9 @@ def exec_pkgconfig(*pkgs_options, **ekw)
                         #/usr/include/gtk-2.0/gtk/gtkitemfactory.h:47:1: error: function declaration isn't a prototype [-Werror=strict-prototypes]
                         #"-Wno-error=strict-prototypes",
                         ]
+                if sys.platform.startswith("netbsd"):
+                    #see: http://trac.cython.org/ticket/395
+                    eifd += ["-fno-strict-aliasing"]
             else:
                 #older versions of OSX ship an old gcc,
                 #not much we can do with this:
