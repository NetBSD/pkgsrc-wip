$NetBSD$

Correctly determine path to the leap-second data file.

XXX Don't hardcode '/usr/pkg'

--- time/chrono/+netbsd.ha.orig	2024-07-14 11:28:01.000000000 +0000
+++ time/chrono/+netbsd.ha
@@ -6,4 +6,4 @@ def TZDB_PATH: str = "/usr/share/zoneinf
 
 // The filepath of the system's "leap-seconds.list" file, which contains UTC/TAI
 // leap second data.
-export def UTC_LEAPSECS_PATH: str = "/usr/share/zoneinfo/leap-seconds.list";
+export def UTC_LEAPSECS_PATH: str = "/usr/pkg/share/hare/leap-seconds.list";
