$NetBSD$

Add pkgsrc ${PREFIX}/share/doom to WAD file search path.

--- src/d_iwad.c.orig	2020-04-14 06:39:44.000000000 +0000
+++ src/d_iwad.c
@@ -677,6 +677,9 @@ static void AddXdgDirs(void)
         env = "/usr/local/share:/usr/share";
     }
 
+    // Add pkgsrc location for WADs
+    AddIWADPath(PKGSRC_PREFIX, PKGSRC_DOOMWADDIR);
+
     // The "standard" location for IWADs on Unix that is supported by most
     // source ports is /usr/share/games/doom - we support this through the
     // XDG_DATA_DIRS mechanism, through which it can be overridden.
