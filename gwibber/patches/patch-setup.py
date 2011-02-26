$NetBSD: patch-setup.py,v 1.1 2011/02/26 11:56:25 ryo-on Exp $

* avoid hard-coded path.

--- setup.py.orig	2011-02-23 03:35:21.000000000 +0000
+++ setup.py
@@ -101,7 +101,7 @@ setup(name="gwibber",
     ('share/gwibber/ui/icons/streams/24x24', glob("ui/icons/streams/24x24/*.svg")),
     ('share/gwibber/ui/icons/streams/scalable', glob("ui/icons/streams/scalable/*.png")),
     ('share/gwibber/ui/icons/streams/scalable', glob("ui/icons/streams/scalable/*.svg")),
-    ('/usr/share/indicators/messages/applications', ['indicator/gwibber']),
+    ('share/indicators/messages/applications', ['indicator/gwibber']),
     ],
       scripts=['bin/gwibber', 'bin/gwibber-service', 'bin/gwibber-poster', 'bin/gwibber-accounts', 'bin/gwibber-preferences', 'bin/gwibber-client'],
       cmdclass = { "build" :  build_extra.build_extra,
