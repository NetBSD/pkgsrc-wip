--- asn.c.orig	2014-01-29 08:21:13.000000000 +0200
+++ asn.c	2014-04-25 11:09:34.000000000 +0300
@@ -47,27 +47,40 @@
 #endif
 */
 
-#define IIHASH_HI	128
-#define ITEMSMAX	15
-#define ITEMSEP	'|'
+#define II_ITEM_SEP	'|'
+#define II_ARGS_SEP	','
 #define NAMELEN	127
 #define UNKN	"???"
 
-int  ipinfo_no = -1;
+int  ipinfo_nos[II_ITEM_MAX + 1] = {-1};
 int  ipinfo_max = -1;
 int  iihash = 0;
-char fmtinfo[32];
-extern int af;                  /* address family of remote target */
+char fmtinfo[NAMELEN + 1];
 
-// items width: ASN, Route, Country, Registry, Allocated 
-int iiwidth[] = { 6, 19, 4, 8, 11};	// item len + space
-int iiwidth_len = sizeof(iiwidth)/sizeof((iiwidth)[0]);
+extern int af;                  /* address family of remote target */
+extern int maxTTL;
 
-typedef char* items_t[ITEMSMAX + 1];
+typedef char* items_t[II_ITEM_MAX + 1];
 items_t items_a;		// without hash: items
 char txtrec[NAMELEN + 1];	// without hash: txtrec
 items_t* items = &items_a;
 
+typedef struct {
+    char* ip4zone;
+    char* ip6zone;
+    int as_prfx_ndx;
+    int width_len;
+    int width[II_ITEM_MAX];
+} ii_origin_t;
+ii_origin_t ii_origins[] = {
+// ASN [ASN ..] | Route | CC | Registry | Allocated
+    { "origin.asn.cymru.com", "origin6.asn.cymru.com", 0, 5, { 6, 19, 4, 8, 11 } },
+// ASN
+    { "asn.routeviews.org", NULL, 0, 1, { 6 } },
+// Route | "AS"ASN | Organization | Allocated | CC
+    { "origin.asn.spameatingmonkey.net", NULL, -1, 5, { 19, 8, 19, 11, 4 } },
+};
+int ii_zone_no = 0;
 
 char *ipinfo_lookup(const char *domain) {
     unsigned char answer[PACKETSZ],  *pt;
@@ -146,18 +159,30 @@
     return txt;
 }
 
-char* trimsep(char *s) {
-    int l;
-    char *p = s;
-    while (*p == ' ' || *p == ITEMSEP)
-        *p++ = '\0';
-    for (l = strlen(p)-1; p[l] == ' ' || p[l] == ITEMSEP; l--)
-        p[l] = '\0';
-    return p;
+int split_with_sep(items_t* it, char sep) {
+    if (!it)
+	return -1;
+    if (!(*it))
+	return -1;
+
+    char* prev = (*it)[0] = trim((*it)[0]);
+    char* next;
+    int i = 0, j;
+
+    while ((next = strchr(prev, sep)) && (i < II_ITEM_MAX)) {
+        *next++ = '\0';
+        (*it)[i++] = trim(prev);
+        (*it)[i] = prev = trim(next);
+    }
+    if (i < II_ITEM_MAX)
+        i++;
+    for (j = i;  j <= II_ITEM_MAX; j++)
+        (*it)[j] = NULL;
+
+    return i;
 }
 
-// originX.asn.cymru.com txtrec:    ASN | Route | Country | Registry | Allocated
-char* split_txtrec(char *txtrec) {
+char* split_txtrec(char *txtrec, int ndx) {
     if (!txtrec)
 	return NULL;
     if (iihash) {
@@ -173,28 +198,44 @@
         }
     }
 
-    char* prev = (*items)[0] = trimsep(txtrec);
-    char* next;
-    int i = 0, j;
-
-    while ((next = strchr(prev, ITEMSEP)) && (i < ITEMSMAX)) {
-        *next++ = '\0';
-        (*items)[i++] = trimsep(prev);
-        (*items)[i] = prev = trimsep(next);
-    }
-    if (i < ITEMSMAX)
-        i++;
-    for (j = i;  j <= ITEMSMAX; j++)
-        (*items)[j] = NULL;
+    (*items)[0] = txtrec;
+    int i = split_with_sep(items, II_ITEM_SEP);
 
     if (i > ipinfo_max)
         ipinfo_max = i;
-    if (ipinfo_no >= i) {
-        if (ipinfo_no >= ipinfo_max)
-            ipinfo_no = 0;
+
+    // special cases
+    if (ii_zone_no == 0) 	{	// cymru.com: MultiAS
+        char *pj = (*items)[ii_origins[ii_zone_no].as_prfx_ndx];
+        if (pj) {
+            char *p;
+            while ((p=strchr(pj, ' ')))
+                *p = '/';
+        }
+    } else if (ii_zone_no == 1) {	// originviews.org: unknown AS
+#define S_UINT32_MAX "4294967295"
+        int j = 0;
+        while ((j < II_ITEM_MAX) && ((*items)[j])) {
+            if (!strncmp((*items)[j], S_UINT32_MAX, sizeof(S_UINT32_MAX)))
+                (*items)[j] = UNKN;
+            j++;
+        }
+    } else if (ii_zone_no == 2) {	// spameatingmonkey.net: unknown info
+#define Unknown "Unknown"
+        int j = 0;
+        while ((j < II_ITEM_MAX) && ((*items)[j])) {
+            if (!strncmp((*items)[j], Unknown, sizeof(Unknown)))
+                (*items)[j] = UNKN;
+            j++;
+        }
+    }
+
+    if (ipinfo_nos[ndx] >= i) {
+        if (ipinfo_nos[ndx] >= ipinfo_max)
+            ipinfo_nos[ndx] = 0;
 	return (*items)[0];
     } else
-	return (*items)[ipinfo_no];
+	return (*items)[ipinfo_nos[ndx]];
 }
 
 #ifdef ENABLE_IPV6
@@ -208,7 +249,7 @@
 }
 #endif
 
-char *get_ipinfo(ip_t *addr) {
+char *get_ipinfo(ip_t *addr, int ndx) {
     if (!addr)
         return NULL;
 
@@ -217,18 +258,22 @@
 
     if (af == AF_INET6) {
 #ifdef ENABLE_IPV6
+        if (!ii_origins[ii_zone_no].ip6zone)
+            return NULL;
         reverse_host6(addr, key);
-        if (snprintf(lookup_key, NAMELEN, "%s.origin6.asn.cymru.com", key) >= NAMELEN)
+        if (snprintf(lookup_key, NAMELEN, "%s.%s", key, ii_origins[ii_zone_no].ip6zone) >= NAMELEN)
             return NULL;
 #else
 	return NULL;
 #endif
     } else {
+        if (!ii_origins[ii_zone_no].ip4zone)
+            return NULL;
         unsigned char buff[4];
         memcpy(buff, addr, 4);
         if (snprintf(key, NAMELEN, "%d.%d.%d.%d", buff[3], buff[2], buff[1], buff[0]) >= NAMELEN)
             return NULL;
-        if (snprintf(lookup_key, NAMELEN, "%s.origin.asn.cymru.com", key) >= NAMELEN)
+        if (snprintf(lookup_key, NAMELEN, "%s.%s", key, ii_origins[ii_zone_no].ip4zone) >= NAMELEN)
             return NULL;
     }
 
@@ -242,7 +287,7 @@
         item.key = key;;
         ENTRY *found_item;
         if ((found_item = hsearch(item, FIND))) {
-            if (!(val = (*((items_t*)found_item->data))[ipinfo_no]))
+            if (!(val = (*((items_t*)found_item->data))[ipinfo_nos[ndx]]))
                 val = (*((items_t*)found_item->data))[0];
 #ifdef IIDEBUG
         syslog(LOG_INFO, "Found (hashed): %s", val);
@@ -254,7 +299,7 @@
 #ifdef IIDEBUG
         syslog(LOG_INFO, "Lookup: %s", key);
 #endif
-        if ((val = split_txtrec(ipinfo_lookup(lookup_key)))) {
+        if ((val = split_txtrec(ipinfo_lookup(lookup_key), ndx))) {
 #ifdef IIDEBUG
             syslog(LOG_INFO, "Looked up: %s", key);
 #endif
@@ -263,7 +308,16 @@
                     item.data = items;
                     hsearch(item, ENTER);
 #ifdef IIDEBUG
-                    syslog(LOG_INFO, "Insert into hash: %s", key);
+                    {
+                        char *p, buff[NAMELEN + 1] = {'\0'};
+                        int i = 0;
+                        while ((p = (*items)[i++])) {
+                            char it[NAMELEN + 1];
+                            snprintf(it, sizeof(it), "\"%s\" ", p);
+                            strncat(buff, it, sizeof(buff) - strlen(buff) -1);
+                        }
+                        syslog(LOG_INFO, "Insert into hash: \"%s\" => %s", key, buff);
+                    }
 #endif
                 }
         }
@@ -272,15 +326,44 @@
     return val;
 }
 
+int get_width(int iino) {
+    int no = iino;
+    if (no >= ii_origins[ii_zone_no].width_len)
+        no %= ii_origins[ii_zone_no].width_len;
+    return ii_origins[ii_zone_no].width[no];
+}
+
 int get_iiwidth(void) {
-    return (ipinfo_no < iiwidth_len) ? iiwidth[ipinfo_no] : iiwidth[ipinfo_no % iiwidth_len];
+    int i, l = 0;
+    for (i = 0; (i <= II_ITEM_MAX) && (ipinfo_nos[i] >= 0); i++) {
+        l += get_width(ipinfo_nos[i]);
+        if (ipinfo_nos[i] == ii_origins[ii_zone_no].as_prfx_ndx)
+            l += 2; // AS prfx
+    }
+    return l;
 }
 
 char *fmt_ipinfo(ip_t *addr) {
-    char *ipinfo = get_ipinfo(addr);
-    char fmt[8];
-    snprintf(fmt, sizeof(fmt), "%s%%-%ds", ipinfo_no?"":"AS", get_iiwidth());
-    snprintf(fmtinfo, sizeof(fmtinfo), fmt, ipinfo?ipinfo:UNKN);
+    int i;
+    fmtinfo[0] = '\0';
+    for (i = 0; (i <= II_ITEM_MAX) && (ipinfo_nos[i] >= 0); i++) {
+        char *ipinfo = get_ipinfo(addr, i);
+
+        char fmt[8], buff[NAMELEN+1];
+        int width = get_width(ipinfo_nos[i]);
+        if (ipinfo_nos[i] != ipinfo_max) {
+          if (ipinfo)
+            if (strnlen(ipinfo, NAMELEN) >= width)
+              width = strnlen(ipinfo, NAMELEN) + 1;
+          snprintf(fmt, sizeof(fmt), "%s%%-%ds",
+              (ipinfo_nos[i] != ii_origins[ii_zone_no].as_prfx_ndx)?"":"AS", width);
+          snprintf(buff, sizeof(buff), fmt, ipinfo?ipinfo:UNKN);
+        } else {	// empty item
+          snprintf(fmt, sizeof(fmt), "  %%-%ds", width);
+          snprintf(buff, sizeof(buff), fmt, "");
+        }
+        strncat(fmtinfo, buff, sizeof(fmtinfo) - strlen(fmtinfo) -1);
+    }
     return fmtinfo;
 }
 
@@ -291,9 +374,9 @@
 void asn_open(void) {
     if (ipinfo_no >= 0) {
 #ifdef IIDEBUG
-        syslog(LOG_INFO, "hcreate(%d)", IIHASH_HI);
+        syslog(LOG_INFO, "hcreate(%d)", maxTTL);
 #endif
-        if (!(iihash = hcreate(IIHASH_HI)))
+        if (!(iihash = hcreate(maxTTL)))
             perror("ipinfo hash");
     }
 }
@@ -308,3 +391,32 @@
     }
 }
 
+void ii_parse(char *arg) {
+    int i, j;
+    for (i = 0; i <= II_ITEM_MAX; i++)
+	ipinfo_nos[i] = -1;
+    items_a[0] = strdup(arg);
+    split_with_sep(&items_a, II_ARGS_SEP);
+
+    int no;
+    if (items_a[0]) {
+        no = atoi(items_a[0]) -1;
+        if ((no >= 0) && (no < (sizeof(ii_origins)/sizeof(ii_origins[0]))))
+        ii_zone_no = no;
+    }
+	if (ii_zone_no < 0)
+		ii_zone_no = 0;
+
+    for (i = 1, j = 0; (i <= II_ITEM_MAX) && items_a[i]; i++) {
+        no = atoi(items_a[i]) -1;
+        if (no >= 0)
+            ipinfo_nos[j++] = no;
+    }
+	if (ipinfo_no < 0)
+		ipinfo_no = 0;
+    free(items_a[0]);
+#ifdef IIDEBUG
+    syslog(LOG_INFO, "ii origin: \"%s\" \"%s\"", ii_origins[ii_zone_no].ip4zone, ii_origins[ii_zone_no].ip6zone);
+#endif
+}
+
