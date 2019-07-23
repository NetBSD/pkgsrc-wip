$NetBSD$

Patches from NetBSD xsrc:

Sat May 9 15:07:49 2015

CID 1225080: check getrlimit return

Sep 21 23:40:14 2009

Add a "-noretro" option to get the new (black background
and no cursor) behavior.

Addresses part of PR xsrc/41870

--- os/utils.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ os/utils.c
@@ -558,6 +558,9 @@ UseMsg(void)
     ErrorF("r                      turns on auto-repeat \n");
     ErrorF("-render [default|mono|gray|color] set render color alloc policy\n");
     ErrorF("-retro                 start with classic stipple and cursor\n");
+#if defined(__NetBSD__)
+    ErrorF("-noretro               start with black background and no cursor\n");
+#endif
     ErrorF("-s #                   screen-saver timeout (minutes)\n");
     ErrorF("-seat string           seat to run on\n");
     ErrorF("-t #                   default pointer threshold (pixels/t)\n");
@@ -735,9 +738,16 @@ ProcessCommandLine(int argc, char *argv[
 #if !defined(WIN32) || !defined(__MINGW32__)
             struct rlimit core_limit;
 
+#if defined(STRICT_XSRC_NETBSD)
+            if (getrlimit(RLIMIT_CORE, &core_limit) != -1) {
+                core_limit.rlim_cur = core_limit.rlim_max;
+                setrlimit(RLIMIT_CORE, &core_limit);
+            }
+#else
             getrlimit(RLIMIT_CORE, &core_limit);
             core_limit.rlim_cur = core_limit.rlim_max;
             setrlimit(RLIMIT_CORE, &core_limit);
+#endif /* STRICT_XSRC_NETBSD */
 #endif
             CoreDump = TRUE;
         }
@@ -909,6 +919,10 @@ ProcessCommandLine(int argc, char *argv[
             defaultKeyboardControl.autoRepeat = FALSE;
         else if (strcmp(argv[i], "-retro") == 0)
             party_like_its_1989 = TRUE;
+#if defined(__NetBSD__)
+	else if (strcmp(argv[i], "-noretro") == 0)
+	    party_like_its_1989 = FALSE;
+#endif
         else if (strcmp(argv[i], "-s") == 0) {
             if (++i < argc)
                 defaultScreenSaverTime = ((CARD32) atoi(argv[i])) *
