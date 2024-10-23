$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-volume-set.c,v 1.2 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- xlators/mgmt/glusterd/src/glusterd-volume-set.c.orig	2023-04-06 09:01:25.037968406 +0000
+++ xlators/mgmt/glusterd/src/glusterd-volume-set.c
@@ -211,7 +211,7 @@ validate_uss_dir(glusterd_volinfo_t *vol
     }
 
     for (i = 1; value[i]; i++) {
-        if (isalnum(value[i]) || value[i] == '_' || value[i] == '-')
+        if (isalnum((unsigned char)value[i]) || value[i] == '_' || value[i] == '-')
             continue;
 
         snprintf(errstr, sizeof(errstr),
