$NetBSD$

Disable test with <clue-string> and no longer use V2 API.

--- test/canlocktest.c.orig	2017-05-08 14:24:53.000000000 +0000
+++ test/canlocktest.c
@@ -80,23 +80,21 @@ static const char *check_scheme(cl_hash_
 static int checker(cl_hash_version hash, char *key, char *lock)
 {
    int res = -1;
-   char *rawkey, *rawlock;
-   char keytype[BUFFSIZE], locktype[BUFFSIZE];
+   cl_hash_version hash_key, hash_lock;
+   char *string_key, *string_lock;
    const char *scheme;
 
    printf("%s\n%s,%s\n", "Check Cancel-Key,Cancel-Lock:", key, lock);
 
-   rawkey = lock_strip_alpha(key, keytype);
-   rawlock = lock_strip_alpha(lock, locktype);
+   hash_key = cl_split(key, &string_key);
+   hash_lock = cl_split(lock, &string_lock);
 
-   /* Check whether <scheme> matches */
-   if (!strcmp(keytype, locktype))
+   if (hash_key && hash_lock)
    {
-      /* Check whether <scheme> is supported */
-      scheme = check_scheme(hash);
-      if (NULL != scheme && !strcmp(keytype, scheme))
+      /* Check whether <scheme> matches */
+      if (hash_key == hash_lock)
       {
-         if (!cl_verify(hash, rawkey, rawlock))
+         if (!cl_verify(hash, string_key, string_lock))
          {
             printf("\nGOOD\n");
             res = 0;
@@ -105,10 +103,11 @@ static int checker(cl_hash_version hash,
             printf("\nBAD\n");
       }
       else
-         printf("\nBAD: Scheme not supported\n");
+         printf("\nBAD: Scheme mismatch (%s/%s)\n",
+                check_scheme(hash_key), check_scheme(hash_lock));
    }
    else
-      printf("\nBAD: Scheme mismatch (%s/%s)\n", keytype, locktype);
+      printf("\nBAD: Scheme not supported\n");
 
    return res;
 }
@@ -224,10 +223,14 @@ int main(void)
 
    /* Test 5 (Check SHA1 with <clue-string> element) */
    printf("Test 5 (Check SHA1 with <clue-string> element)\n\n");
+#if 0  /* Skip because it requires V2 API */
    c_key = "ShA1:aaaBBBcccDDDeeeFFF:bN";
    c_lock = "sha1:bNXHc6ohSmeHaRHHW56BIWZJt+4=";
    rv = checker(CL_SHA1, c_key, c_lock);
    if (rv) failed = 1;
+#endif
+   printf("SKIP\n");
+   printf("(Note: <clue-string> is obsolete since >20 years)\n");
    printf("\n----------------------------------------"
           "----------------------------------------\n\n");
 
