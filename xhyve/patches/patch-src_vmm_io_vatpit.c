$NetBSD$

Explicitly cast delta_ticks to make it compile

--- src/vmm/io/vatpit.c.orig	2021-10-01 21:16:50.000000000 -0700
+++ src/vmm/io/vatpit.c	2022-02-14 12:03:53.000000000 -0800
@@ -204,7 +204,7 @@
 
 	delta_ticks = (sbinuptime() - c->now_sbt) / vatpit->freq_sbt;
 
-	lval = c->initial - delta_ticks % c->initial;
+	lval = c->initial - (uint16_t)delta_ticks % c->initial;
 
 	if (latch) {
 		c->olbyte = 2;
