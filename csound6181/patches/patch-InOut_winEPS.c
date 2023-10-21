$NetBSD$

Add NetBSD and DragonFlyBSD support.

--- InOut/winEPS.c.orig 2022-11-23 19:53:55.000000000 +0000
+++ InOut/winEPS.c
@@ -144,7 +144,7 @@ void PS_MakeGraph(CSOUND *csound, WINDAT
      *  Get the current time and date
      */
     lt = time(NULL);
-#ifndef LINUX
+#if !defined(LINUX) && !defined(__NetBSD__) && !defined(__DragonFly__)
     {
       struct tm *date_ptr;
       char      *date;
