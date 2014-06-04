--- asn.c.orig	2014-06-04 13:13:26.000000000 +0300
+++ asn.c	2014-06-04 13:14:17.000000000 +0300
@@ -47,34 +47,47 @@
 #endif
 */
 
-#define IIHASH_HI	128
-#define ITEMSMAX	15
-#define ITEMSEP	'|'
-#define NAMELEN	127
+#define II_ARGS_SEP	','
+#define II_ITEM_SEP	'|'
+#define II_ITEM_MAX	5
+#define NAMELEN	128
 #define UNKN	"???"
 
-int  ipinfo_no = -1;
-int  ipinfo_max = -1;
-int  iihash = 0;
-char fmtinfo[32];
 extern int af;                  /* address family of remote target */
+extern int maxTTL;
 
-// items width: ASN, Route, Country, Registry, Allocated 
-int iiwidth[] = { 6, 19, 4, 8, 11};	// item len + space
-int iiwidth_len = sizeof(iiwidth)/sizeof((iiwidth)[0]);
-
-typedef char* items_t[ITEMSMAX + 1];
-items_t items_a;		// without hash: items
-char txtrec[NAMELEN + 1];	// without hash: txtrec
-items_t* items = &items_a;
+int enable_ipinfo;
 
+static int hash;
+static int origin_no;
+static int ipinfo_no[II_ITEM_MAX] = {-1};
+static int ipinfo_max;
+
+typedef char* items_t[II_ITEM_MAX];
+static items_t* items;
+
+typedef struct {
+    char* ip4zone;
+    char* ip6zone;
+    int as_prfx_ndx;
+    int fields;
+    int width[II_ITEM_MAX];
+} origin_t;
+static origin_t origins[] = {
+// ASN [ASN ..] | Route | CC | Registry | Allocated
+    { "origin.asn.cymru.com", "origin6.asn.cymru.com", 0, 5, { 6, 17, 4, 8, 11 } },
+// ASN
+    { "asn.routeviews.org", NULL, 0, 1, { 6 } },
+// Route | "AS"ASN | Organization | Allocated | CC
+    { "origin.asn.spameatingmonkey.net", NULL, -1, 5, { 17, 8, 17, 11, 4 } },
+};
 
 char *ipinfo_lookup(const char *domain) {
     unsigned char answer[PACKETSZ],  *pt;
     char host[128];
     char *txt;
     int len, exp, size, txtlen, type;
-
+    static char txtrec[NAMELEN];
 
     if(res_init() < 0) {
         fprintf(stderr,"@res_init failed\n");
@@ -84,10 +97,10 @@
     memset(answer, 0, PACKETSZ);
     if((len = res_query(domain, C_IN, T_TXT, answer, PACKETSZ)) < 0) {
 #ifdef IIDEBUG
-        if (iihash)
+        if (hash)
             syslog(LOG_INFO, "Malloc-txt: %s", UNKN);
 #endif
-        return (iihash)?strdup(UNKN):UNKN;
+        return (hash)?strdup(UNKN):UNKN;
     }
 
     pt = answer + sizeof(HEADER);
@@ -128,7 +141,7 @@
     if (txtlen > NAMELEN)
         txtlen = NAMELEN;
 
-    if (iihash) {
+    if (hash) {
         if (!(txt = malloc(txtlen + 1)))
             return NULL;
     } else
@@ -139,62 +152,93 @@
     txt[txtlen] = 0;
 
 #ifdef IIDEBUG
-    if (iihash)
+    if (hash)
         syslog(LOG_INFO, "Malloc-txt(%p): %s", txt, txt);
 #endif
 
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
+int split_with_sep(char** args, int max, char sep) {
+    if (!args)
+        return -1;
+
+    int i;
+    char *p = *args, **a = args + 1;
+    for (i = 0; (p = strchr(p, sep)) && (i < max); i++, *a++ = p)
+        *p++ = 0;
+    int j;
+    for (j = 0; j < max; j++)
+        if (args[j])
+            args[j] = trim(args[j]);
+
+    return (i + 1);
 }
 
-// originX.asn.cymru.com txtrec:    ASN | Route | Country | Registry | Allocated
-char* split_txtrec(char *txtrec) {
-    if (!txtrec)
+char* split_rec(char *rec, int ndx) {
+    if (!rec)
 	return NULL;
-    if (iihash) {
+    if (hash) {
 #ifdef IIDEBUG
-        syslog(LOG_INFO, "Malloc-tbl: %s", txtrec);
+        syslog(LOG_INFO, "Malloc-tbl: %s", rec);
 #endif
         if (!(items = malloc(sizeof(*items)))) {
 #ifdef IIDEBUG
-            syslog(LOG_INFO, "Free-txt(%p)", txtrec);
+            syslog(LOG_INFO, "Free-txt(%p)", rec);
 #endif
-            free(txtrec);
+            free(rec);
             return NULL;
         }
-    }
-
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
+    } else {
+#ifdef IIDEBUG
+        syslog(LOG_INFO, "Not hashed: %s", rec);
+#endif
+        static items_t nothashed_items;
+        items = &nothashed_items;
+	}
+
+    memset(items, 0, sizeof(*items));
+    (*items)[0] = rec;
+    int i = split_with_sep((char**)items, II_ITEM_MAX, II_ITEM_SEP);
 
     if (i > ipinfo_max)
         ipinfo_max = i;
-    if (ipinfo_no >= i) {
-        if (ipinfo_no >= ipinfo_max)
-            ipinfo_no = 0;
-	return (*items)[0];
+
+    // special cases
+    switch (origin_no) {
+      case 0: {	// cymru.com: MultiAS
+        char *p = (*items)[origins[0].as_prfx_ndx];
+        if (p) {
+            char *last = p + strnlen(p, NAMELEN) - 1;
+            while ((p = strchr(p, ' ')))
+                if (p != last)
+                    *p = '/';
+                else
+                    break;
+        }
+      } break;
+      case 1: {	// originviews.org: unknown AS
+#define S_UINT32_MAX "4294967295"
+        int j;
+        for (j = 0; (j < II_ITEM_MAX) && (*items)[j]; j++)
+            if (!strncmp((*items)[j], S_UINT32_MAX, sizeof(S_UINT32_MAX)))
+                (*items)[j] = UNKN;
+      } break;
+      case 2: {	// spameatingmonkey.net: unknown info
+#define Unknown "Unknown"
+        int j;
+        for (j = 0; (j < II_ITEM_MAX) && (*items)[j]; j++)
+            if (!strncmp((*items)[j], Unknown, sizeof(Unknown)))
+                (*items)[j] = UNKN;
+      } break;
+    }
+
+    if (ipinfo_no[ndx] >= i) {
+        if (ipinfo_no[ndx] >= ipinfo_max)
+            ipinfo_no[ndx] = 0;
+        return (*items)[0];
     } else
-	return (*items)[ipinfo_no];
+        return (*items)[ipinfo_no[ndx]];
 }
 
 #ifdef ENABLE_IPV6
@@ -204,11 +248,11 @@
     char *b = buff;
     for (i=(sizeof(*addr)/2-1); i>=0; i--, b+=4) // 64b portion
         sprintf(b, "%x.%x.", addr->s6_addr[i] & 0xf, addr->s6_addr[i] >> 4);
-    buff[strlen(buff) - 1] = '\0';
+    buff[strlen(buff) - 1] = 0;
 }
 #endif
 
-char *get_ipinfo(ip_t *addr) {
+char *get_ipinfo(ip_t *addr, int ndx) {
     if (!addr)
         return NULL;
 
@@ -217,32 +261,36 @@
 
     if (af == AF_INET6) {
 #ifdef ENABLE_IPV6
+        if (!origins[origin_no].ip6zone)
+            return NULL;
         reverse_host6(addr, key);
-        if (snprintf(lookup_key, NAMELEN, "%s.origin6.asn.cymru.com", key) >= NAMELEN)
+        if (snprintf(lookup_key, NAMELEN, "%s.%s", key, origins[origin_no].ip6zone) >= NAMELEN)
             return NULL;
 #else
 	return NULL;
 #endif
     } else {
+        if (!origins[origin_no].ip4zone)
+            return NULL;
         unsigned char buff[4];
         memcpy(buff, addr, 4);
         if (snprintf(key, NAMELEN, "%d.%d.%d.%d", buff[3], buff[2], buff[1], buff[0]) >= NAMELEN)
             return NULL;
-        if (snprintf(lookup_key, NAMELEN, "%s.origin.asn.cymru.com", key) >= NAMELEN)
+        if (snprintf(lookup_key, NAMELEN, "%s.%s", key, origins[origin_no].ip4zone) >= NAMELEN)
             return NULL;
     }
 
     char *val = NULL;
     ENTRY item;
 
-    if (iihash) {
+    if (hash) {
 #ifdef IIDEBUG
         syslog(LOG_INFO, ">> Search: %s", key);
 #endif
-        item.key = key;;
+        item.key = key;
         ENTRY *found_item;
         if ((found_item = hsearch(item, FIND))) {
-            if (!(val = (*((items_t*)found_item->data))[ipinfo_no]))
+            if (!(val = (*((items_t*)found_item->data))[ipinfo_no[ndx]]))
                 val = (*((items_t*)found_item->data))[0];
 #ifdef IIDEBUG
         syslog(LOG_INFO, "Found (hashed): %s", val);
@@ -254,16 +302,24 @@
 #ifdef IIDEBUG
         syslog(LOG_INFO, "Lookup: %s", key);
 #endif
-        if ((val = split_txtrec(ipinfo_lookup(lookup_key)))) {
+        if ((val = split_rec(ipinfo_lookup(lookup_key), ndx))) {
 #ifdef IIDEBUG
             syslog(LOG_INFO, "Looked up: %s", key);
 #endif
-            if (iihash)
+            if (hash)
                 if ((item.key = strdup(key))) {
                     item.data = items;
                     hsearch(item, ENTER);
 #ifdef IIDEBUG
-                    syslog(LOG_INFO, "Insert into hash: %s", key);
+                    {
+                        char buff[NAMELEN] = {0};
+                        int i, len = 0;
+                        for (i = 0; (i < II_ITEM_MAX) && (*items)[i]; i++) {
+                            snprintf(buff + len, sizeof(buff) - len, "\"%s\" ", (*items)[i]);
+                            len = strnlen(buff, sizeof(buff));
+                        }
+                        syslog(LOG_INFO, "Insert into hash: \"%s\" => %s", key, buff);
+                    }
 #endif
                 }
         }
@@ -272,39 +328,115 @@
     return val;
 }
 
-int get_iiwidth(void) {
-    return (ipinfo_no < iiwidth_len) ? iiwidth[ipinfo_no] : iiwidth[ipinfo_no % iiwidth_len];
+int ii_getwidth(void) {
+    int i, l = 0;
+    for (i = 0; (i < II_ITEM_MAX) && (ipinfo_no[i] >= 0); i++) {
+        l += origins[origin_no].width[ipinfo_no[i]];
+        if (ipinfo_no[i] == origins[origin_no].as_prfx_ndx)
+            l += 2; // AS prfx
+    }
+    return l;
 }
 
 char *fmt_ipinfo(ip_t *addr) {
-    char *ipinfo = get_ipinfo(addr);
-    char fmt[8];
-    snprintf(fmt, sizeof(fmt), "%s%%-%ds", ipinfo_no?"":"AS", get_iiwidth());
-    snprintf(fmtinfo, sizeof(fmtinfo), fmt, ipinfo?ipinfo:UNKN);
+    static char fmtinfo[NAMELEN];
+    int len = 0;
+    int i;
+    for (i = 0; (i < II_ITEM_MAX) && (ipinfo_no[i] >= 0); i++) {
+        char *ipinfo = get_ipinfo(addr, i);
+        char fmt[8];
+        int width = origins[origin_no].width[ipinfo_no[i]];
+        if (ipinfo_no[i] != ipinfo_max) {
+          if (ipinfo) {
+            int l = strnlen(ipinfo, NAMELEN);
+            if (!l)
+              ipinfo = UNKN;
+            if (l >= width)
+              width = strnlen(ipinfo, NAMELEN) + 1;	// +1 for space
+          } else
+            ipinfo = UNKN;
+          snprintf(fmt, sizeof(fmt), "%s%%-%ds",
+              (ipinfo_no[i] == origins[origin_no].as_prfx_ndx) ? "AS" : "", width);
+          snprintf(fmtinfo + len, sizeof(fmtinfo) - len, fmt, ipinfo);
+          len = strnlen(fmtinfo, sizeof(fmtinfo));
+        } else {	// empty item
+          snprintf(fmt, sizeof(fmt), "  %%-%ds", width);
+          snprintf(fmtinfo + len, sizeof(fmtinfo) - len, fmt, "");
+          len = strnlen(fmtinfo, sizeof(fmtinfo));
+        }
+    }
     return fmtinfo;
 }
 
-int is_printii(void) {
-    return ((ipinfo_no >= 0) && (ipinfo_no != ipinfo_max));
-}
-
 void asn_open(void) {
-    if (ipinfo_no >= 0) {
+    if (!hash) {
 #ifdef IIDEBUG
-        syslog(LOG_INFO, "hcreate(%d)", IIHASH_HI);
+        syslog(LOG_INFO, "hcreate(%d)", maxTTL);
 #endif
-        if (!(iihash = hcreate(IIHASH_HI)))
+        if (!(hash = hcreate(maxTTL)))
             perror("ipinfo hash");
     }
 }
 
 void asn_close(void) {
-    if (iihash) {
+    if (hash) {
 #ifdef IIDEBUG
         syslog(LOG_INFO, "hdestroy()");
 #endif
         hdestroy();
-        iihash = 0;
+        hash = enable_ipinfo = 0;
     }
 }
 
+void ii_parsearg(char *arg) {
+    if (!hash)
+        asn_open();
+
+    char* args[II_ITEM_MAX + 1];
+    memset(args, 0, sizeof(args));
+    args[0] = strdup(arg);
+    split_with_sep((char**)&args, II_ITEM_MAX + 1, II_ARGS_SEP);
+
+    if (args[0]) {
+        int no = atoi(args[0]);
+        if ((no > 0) && (no <= (sizeof(origins)/sizeof(origins[0]))))
+            origin_no = no - 1;
+    }
+
+    int i, j;
+    for (i = 1, j = 0; (j < II_ITEM_MAX) && (i <= II_ITEM_MAX); i++)
+		if (args[i]) {
+    	    int no = atoi(args[i]);
+       	    if ((no > 0) && (no <= origins[origin_no].fields))
+       	        ipinfo_no[j++] = no - 1;
+    	}
+    for (i = j; i < II_ITEM_MAX; i++)
+        ipinfo_no[i] = -1;
+    if (ipinfo_no[0] < 0)
+        ipinfo_no[0] = 0;
+
+    free(args[0]);
+    enable_ipinfo = 1;
+#ifdef IIDEBUG
+    syslog(LOG_INFO, "ii origin: \"%s\" \"%s\"", origins[origin_no].ip4zone, origins[origin_no].ip6zone);
+#endif
+}
+
+void ii_action(int action_asn) {
+   if (!hash)
+       asn_open();
+
+   if (ipinfo_no[0] >= 0) {
+       int i;
+       for (i = 0; (i < II_ITEM_MAX) && (ipinfo_no[i] >= 0); i++) {
+           ipinfo_no[i]++;
+           if (ipinfo_no[i] > ipinfo_max)
+               ipinfo_no[i] = 0;
+       }
+       enable_ipinfo = (ipinfo_no[0] != ipinfo_max) ? 1 : 0;
+   } else	// init
+       ii_parsearg(action_asn ? "2" : "");
+       // action asn:	origin 2:	asn.routeviews.org
+       // action ipinfo:	default origin:	origin.asn.cymru.com
+}
+
