$NetBSD$

	Add missing free*() calls to keep smartalloc happy

--- core/src/stored/btape.cc.orig	2019-01-31 11:39:26.000000000 +0000
+++ core/src/stored/btape.cc
@@ -333,6 +333,7 @@ int main(int margc, char *margv[])
 static void TerminateBtape(int status)
 {
    Dsm_check(200);
+   FreePlugins(jcr);
    FreeJcr(jcr);
    jcr = NULL;
 
@@ -379,6 +380,8 @@ static void TerminateBtape(int status)
    }
 
    StopWatchdog();
+   FlushCryptoCache();
+   UnloadSdPlugins();
    TermMsg();
    TermLastJobsList();
    CloseMemoryPool();               /* free memory in pool */
