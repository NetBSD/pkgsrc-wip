$NetBSD: patch-Nucleus-NucleusPTime.cxx,v 1.2 2012/12/01 15:28:03 darcy Exp $

- Add Dragonfly support

--- src/ptlib/Nucleus++/NucleusPTime.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/Nucleus++/NucleusPTime.cxx
@@ -302,7 +302,7 @@ int PTime::GetTimeZone(PTime::TimeZoneTy
     return tz;
   else
     return tz + ::daylight*60;
-#elif defined(P_FREEBSD)
+#elif defined(P_FREEBSD) || defined(P_DRAGONFLY)
   time_t t;
   time(&t);
   struct tm  * tm = localtime(&t);
