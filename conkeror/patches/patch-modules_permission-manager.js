$NetBSD$

From dc67cae174477498b2f2c7f5d0bc63971a210df2 Mon Sep 17 00:00:00 2001
From: Matt Lundin
Date: Mon, 27 Jun 2016 21:37:38 -0500
Subject: [PATCH] Use new nsIPermission api

* modules/permission-manager.js: Use new api for Mozilla/Firefox
  versions 42 and up. The new api uses protocol://domain instead of a
  simple domain (e.g., https://google.com instead of google.com).
---
 modules/permission-manager.js | 29 +++++++++++++++++++++++------
 1 file changed, 23 insertions(+), 6 deletions(-)

diff --git a/modules/permission-manager.js b/modules/permission-manager.js
index b2d54e1..803b329 100644
--- modules/permission-manager.js
+++ modules/permission-manager.js
@@ -96,7 +96,11 @@ interactive("permission-manager", "View or edit the host-specific "
                     let max_type_len = 0;
                     while (e.hasMoreElements()) {
                         let p = e.getNext().QueryInterface(Ci.nsIPermission);
-                        let host = p.host;
+                        let host;
+                        if (version_compare(get_mozilla_version(), "42.0") >= 0)
+                            host = p.principal.origin;
+                        else
+                            host = p.host;
                         let type = p.type;
                         let cap = p.capability;
                         if (max_host_len < host.length)
@@ -128,9 +132,13 @@ interactive("permission-manager", "View or edit the host-specific "
                         file_buf += "\n";
                 }
 
+                let example = (version_compare(get_mozilla_version(), "42.0") >= 0) ?
+                    "https://google.com" : "google.com";
+                let url_type = (version_compare(get_mozilla_version(), "42.0") >= 0) ?
+                    "protocol://domain" : "domain";
                 file_buf += "\n" +
-                    "# entry syntax (one per line): <domain> <type> <permission>\n\n" +
-                    "# example: google.com popup allow\n\n" +
+                    "# entry syntax (one per line): <" + url_type + "> <type> <permission>\n\n" +
+                    "# example: " + example + " popup allow\n\n" +
 
                     word_wrap("The <domain> must be a valid domain name.  Depending on the <type>, only exact " +
                               "matches may be used, or alternatively it may match any sub-domain if a more " +
@@ -243,14 +251,23 @@ interactive("permission-manager", "View or edit the host-specific "
                                 }
                                 delete existing_perms[""+[host,type]];
                             }
-                            if (add)
-                                permission_manager.add(make_uri("http://" + host), type, cap);
+                            if (add) {
+                                if (version_compare(get_mozilla_version(), "42.0") >= 0) {
+                                    permission_manager.add(make_uri(host), type, cap);
+                                } else {
+                                    permission_manager.add(make_uri("http://" + host), type, cap);
+                                }
+                            }
                         }
                         let num_removed = 0;
                         for (let [k,v] in Iterator(existing_perms)) {
                             let [host,type] = k.split(",",2);
                             ++num_removed;
-                            permission_manager.remove(host,type);
+                            if (version_compare(get_mozilla_version(), "42.0") >= 0) {
+                                permission_manager.remove(make_uri(host),type);
+                            } else {
+                                permission_manager.remove(host,type);
+                            }
                         }
                         let msg;
                         if (num_added == 0 && num_changed == 0 && num_removed == 0)
-- 
2.7.4.GIT

