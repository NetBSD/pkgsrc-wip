$NetBSD$

Fix support for ATmega324PA.

--- include/avr/power.h.orig	2016-02-07 22:59:49.000000000 +0000
+++ include/avr/power.h
@@ -1303,6 +1303,7 @@ __power_all_disable()
 || defined(__AVR_ATmega256RFR2__) \
 || defined(__AVR_ATmega324A__) \
 || defined(__AVR_ATmega324P__) \
+|| defined(__AVR_ATmega324PA__) \
 || defined(__AVR_ATmega325__) \
 || defined(__AVR_ATmega325A__) \
 || defined(__AVR_ATmega325PA__) \
