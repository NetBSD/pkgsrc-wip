$NetBSD$

Fix comments for ATmega324PA.

--- include/avr/wdt.h.orig	2024-06-10 15:19:10.716120078 +0000
+++ include/avr/wdt.h
@@ -590,7 +590,7 @@ void wdt_disable (void)
     ATtiny25, ATtiny45, ATtiny85, 
     ATtiny261, ATtiny461, ATtiny861, 
     ATmega48*, ATmega88*, ATmega168*, ATmega328*,
-    ATmega164P, ATmega324P, ATmega324PB, ATmega644P, ATmega644,
+    ATmega164P, ATmega324P, ATmega324PA, ATmega324PB, ATmega644P, ATmega644,
     ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
     ATmega8HVA, ATmega16HVA, ATmega32HVB,
     ATmega406, ATmega1284P,
@@ -614,7 +614,7 @@ void wdt_disable (void)
     ATtiny25, ATtiny45, ATtiny85, 
     ATtiny261, ATtiny461, ATtiny861, 
     ATmega48*, ATmega88*, ATmega168*, ATmega328*,
-    ATmega164P, ATmega324P, ATmega324PB, ATmega644P, ATmega644,
+    ATmega164P, ATmega324P, ATmega324PA, ATmega324PB, ATmega644P, ATmega644,
     ATmega640, ATmega1280, ATmega1281, ATmega2560, ATmega2561,
     ATmega8HVA, ATmega16HVA, ATmega32HVB,
     ATmega406, ATmega1284P,
