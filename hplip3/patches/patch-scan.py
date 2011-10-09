$NetBSD: patch-scan.py,v 1.1 2011/10/09 00:31:12 gregoire Exp $

--- scan.py.orig	2011-07-24 19:07:25.000000000 +0000
+++ scan.py
@@ -620,10 +620,11 @@ try:
         scan_px = scan_area * res * res / 645.16 # res is in DPI
         
         valid_res = device.getOptionObj('resolution').constraint
-        log.debug("Device supported resolutions %s" % valid_res)
+        log.debug("Device supported resolutions %s" % ', '.join([str(x) for x in valid_res]))
         if res not in valid_res:
             log.warn("Invalid resolution. Using closest valid resolution of %d dpi" % res)
             log.warn("Valid resolutions are %s dpi." % ', '.join([str(x) for x in valid_res]))
+            r = res
             res = valid_res[0]
             min_dist = sys.maxint
             for x in valid_res:
