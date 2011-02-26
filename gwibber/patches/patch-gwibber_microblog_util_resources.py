$NetBSD: patch-gwibber_microblog_util_resources.py,v 1.1 2011/02/26 11:56:25 ryo-on Exp $

* workaround, this is only test. I will fix hard-coded path later.

--- gwibber/microblog/util/resources.py.orig	2011-02-26 11:23:17.000000000 +0000
+++ gwibber/microblog/util/resources.py
@@ -38,7 +38,7 @@ THEME_MIN_VERSION = 2
 
 try:
   import xdg
-  DATA_BASE_DIRS = xdg.BaseDirectory.xdg_data_dirs
+  DATA_BASE_DIRS = ["/usr/pkg/share"]
   CACHE_BASE_DIR = xdg.BaseDirectory.xdg_cache_home
 except:
   DATA_BASE_DIRS = [
