$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- dpi/bookmarks.c.orig	2026-01-06 16:25:07.197502866 +0000
+++ dpi/bookmarks.c
@@ -338,8 +338,8 @@ static void Unencode_str(char *e_str)
             *p = '\n';
             e += 5;
          } else {
-            *p = (isdigit(e[1]) ? (e[1] - '0') : (e[1] - 'A' + 10)) * 16 +
-                 (isdigit(e[2]) ? (e[2] - '0') : (e[2] - 'A' + 10));
+            *p = (isdigit((unsigned char)e[1]) ? (e[1] - '0') : (e[1] - 'A' + 10)) * 16 +
+                 (isdigit((unsigned char)e[2]) ? (e[2] - '0') : (e[2] - 'A' + 10));
             e += 2;
          }
       } else {
@@ -807,11 +807,11 @@ static void Bmsrv_count_urls_and_section
    *n_sec = *n_url = 0;
    if ((p = strchr(url, '?'))) {
       for (q = p; (q = strstr(q, "&url")); ++q) {
-         for (i = 0; isdigit(q[4+i]); ++i);
+         for (i = 0; isdigit((unsigned char)q[4+i]); ++i);
          *n_url += (q[4+i] == '=') ? 1 : 0;
       }
       for (q = p; (q = strstr(q, "&s")); ++q) {
-         for (i = 0; isdigit(q[2+i]); ++i);
+         for (i = 0; isdigit((unsigned char)q[2+i]); ++i);
          *n_sec += (q[2+i] == '=') ? 1 : 0;
       }
    }
@@ -972,7 +972,7 @@ static int Bmsrv_send_modify_update(Dsh 
       /* send items here */
       p = strchr(url1, '?');
       for (q = p; (q = strstr(q, "&s")); ++q) {
-         for (i = 0; isdigit(q[2+i]); ++i);
+         for (i = 0; isdigit((unsigned char)q[2+i]); ++i);
          if (q[2+i] == '=') {
             key = strtol(q + 2, NULL, 10);
             if ((sec_node = Bms_get_sec(key))) {
@@ -992,7 +992,7 @@ static int Bmsrv_send_modify_update(Dsh 
       /* send items here */
       p = strchr(url1, '?');
       for (q = p; (q = strstr(q, "&url")); ++q) {
-         for (i = 0; isdigit(q[4+i]); ++i);
+         for (i = 0; isdigit((unsigned char)q[4+i]); ++i);
          if (q[4+i] == '=') {
             key = strtol(q + 4, NULL, 10);
             bm_node = Bms_get(key);
@@ -1060,7 +1060,7 @@ static int Bmsrv_modify_delete(char *url
    /* Remove marked sections */
    p = strchr(url, '?');
    for (ns = 0; (p = strstr(p, "&s")); ++p) {
-      if (isdigit(p[2])) {
+      if (isdigit((unsigned char)p[2])) {
          key = strtol(p + 2, NULL, 10);
          Bms_sec_del(key);
          ++ns;
@@ -1070,7 +1070,7 @@ static int Bmsrv_modify_delete(char *url
    /* Remove marked urls */
    p = strchr(url, '?');
    for (nb = 0; (p = strstr(p, "&url")); ++p) {
-      if (isdigit(p[4])) {
+      if (isdigit((unsigned char)p[4])) {
          key = strtol(p + 4, NULL, 10);
          Bms_del(key);
          ++nb;
@@ -1105,7 +1105,7 @@ static int Bmsrv_modify_move(char *url)
 
    /* get target section */
    for (p = url; (p = strstr(p, "&s")); ++p) {
-      if (isdigit(p[2])) {
+      if (isdigit((unsigned char)p[2])) {
          section = strtol(p + 2, NULL, 10);
          break;
       }
@@ -1116,7 +1116,7 @@ static int Bmsrv_modify_move(char *url)
    /* move marked urls */
    p = strchr(url, '?');
    for (n = 0; (p = strstr(p, "&url")); ++p) {
-      if (isdigit(p[4])) {
+      if (isdigit((unsigned char)p[4])) {
          key = strtol(p + 4, NULL, 10);
          Bms_move(key, section);
          ++n;
@@ -1145,7 +1145,7 @@ static int Bmsrv_modify_update(char *url
    p = strchr(url, '?');
    for (  ; (p = strstr(p, "s")); ++p) {
       if (p[-1] == '&' || p[-1] == '?' ) {
-         for (i = 0; isdigit(p[1 + i]); ++i);
+         for (i = 0; isdigit((unsigned char)p[1 + i]); ++i);
          if (i && p[1 + i] == '=') {
             /* we have a title/key to change */
             key = strtol(p + 1, NULL, 10);
@@ -1164,7 +1164,7 @@ static int Bmsrv_modify_update(char *url
    p = strchr(url, '?');
    for (  ; (p = strstr(p, "title")); ++p) {
       if (p[-1] == '&' || p[-1] == '?' ) {
-         for (i = 0; isdigit(p[5 + i]); ++i);
+         for (i = 0; isdigit((unsigned char)p[5 + i]); ++i);
          if (i && p[5 + i] == '=') {
             /* we have a title/key to change */
             key = strtol(p + 5, NULL, 10);
@@ -1229,7 +1229,7 @@ static int Bmsrv_modify_add_url(Dsh *sh,
    if (sh == NULL) {
       /* look for section */
       for (q = s_url; (q = strstr(q, "&s")); ++q) {
-         for (i = 0; isdigit(q[2+i]); ++i);
+         for (i = 0; isdigit((unsigned char)q[2+i]); ++i);
          if (q[2+i] == '=')
             section = strtol(q + 2, NULL, 10);
       }
