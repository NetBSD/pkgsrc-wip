$NetBSD$

Fix build with vala 0.56
https://github.com/dino/dino/issues/1576

--- plugins/gpgme-vala/vapi/gpgme_public.vapi.orig	2024-05-15 10:07:26.045175155 +0000
+++ plugins/gpgme-vala/vapi/gpgme_public.vapi
@@ -22,9 +22,9 @@ public class Key {
     public string issuer_name;
     public string chain_id;
     public Validity owner_trust;
-    [CCode(array_null_terminated = true)]
+    [CCode (array_length = false, array_null_terminated = true)]
     public SubKey[] subkeys;
-    [CCode(array_null_terminated = true)]
+    [CCode (array_length = false, array_null_terminated = true)]
     public UserID[] uids;
     public KeylistMode keylist_mode;
     // public string fpr; // requires gpgme >= 1.7.0
