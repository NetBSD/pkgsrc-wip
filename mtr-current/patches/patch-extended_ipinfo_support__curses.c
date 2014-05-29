--- curses.c.orig	2014-05-29 12:31:51.000000000 +0300
+++ curses.c	2014-05-14 11:15:04.000000000 +0300
@@ -345,7 +345,7 @@
       if (! net_up(at))
 	attron(A_BOLD);
 #ifdef IPINFO
-      if (is_printii())
+      if (enable_ipinfo)
         printw(fmt_ipinfo(addr));
 #endif
       if(name != NULL) {
@@ -402,7 +402,7 @@
         if (! net_up(at)) attron(A_BOLD);
         printw("\n    ");
 #ifdef IPINFO
-        if (is_printii())
+        if (enable_ipinfo)
           printw(fmt_ipinfo(addrs));
 #endif
         if (name != NULL) {
@@ -553,7 +553,7 @@
 			attron(A_BOLD);
 		if (addrcmp((void *) addr, (void *) &unspec_addr, af)) {
 #ifdef IPINFO
-			if (is_printii())
+			if (enable_ipinfo)
 				printw(fmt_ipinfo(addr));
 #endif
 			name = dns_lookup(addr);
@@ -643,8 +643,8 @@
     char msg[80];
     int padding = 30;
 #ifdef IPINFO
-    if (is_printii())
-      padding += get_iiwidth();
+    if (enable_ipinfo)
+      padding += ii_getwidth();
 #endif
     int max_cols = maxx<=SAVED_PINGS+padding ? maxx-padding : SAVED_PINGS;
     startstat = padding - 2;
