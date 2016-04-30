$NetBSD$

Improve stability on NetBSD.
(Without this, every tab crashes immediately.)

--- modules/libpref/init/all.js.orig	2016-04-30 15:56:45.719667832 +0000
+++ modules/libpref/init/all.js
@@ -4531,7 +4531,7 @@ pref("device.sensors.enabled", true);
 pref("device.storage.enabled", false);
 
 // Toggle which thread the HTML5 parser uses for stream parsing
-pref("html5.offmainthread", true);
+pref("html5.offmainthread", false);
 // Time in milliseconds between the time a network buffer is seen and the
 // timer firing when the timer hasn't fired previously in this parse in the
 // off-the-main-thread HTML5 parser.
