$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/datetime.d.orig	2020-05-07 08:52:18.694674201 +0000
+++ runtime/phobos/std/datetime.d
@@ -26532,6 +26532,7 @@ auto tz = TimeZone.getTimeZone("America/
         {
             version(FreeBSD)           enum utcZone = "Etc/UTC";
             else version(DragonFlyBSD) enum utcZone = "UTC";
+            else version(NetBSD)       enum utcZone = "UTC";
             else version(linux)        enum utcZone = "UTC";
             else version(OSX)          enum utcZone = "UTC";
             else version(Solaris)      enum utcZone = "UTC";
