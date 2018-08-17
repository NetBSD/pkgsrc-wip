$NetBSD$

Execute legacy tests as NOP if V2 API is disabled.

--- test/canlocktest_legacy.c.orig	2017-05-07 14:53:45.000000000 +0000
+++ test/canlocktest_legacy.c
@@ -49,6 +49,7 @@
 #define BUFFSIZE 512
 
 
+#if CL_API_V2
 static int checker(char *key, char *lock)
 {
    int res = -1;
@@ -80,10 +81,12 @@ static int checker(char *key, char *lock
 
    return res;
 }
+#endif  /* CL_API_V2 */
 
 
 int main(void)
 {
+#if CL_API_V2
    char cankey[256], canlock[256], *lkey, *llock;
    unsigned char secret[] = "fluffy",
       message[] = "<lkr905851929.22670@meow.invalid>";
@@ -146,4 +149,8 @@ int main(void)
    /* Check for success */
    if (!failed) exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
+#else  /* CL_API_V2 */
+   /* Without V2 API: Execute as NOP and return success */
+   exit(EXIT_SUCCESS);
+#endif  /* CL_API_V2 */
 }
