$NetBSD$

Remove API calls deprecated in OpenSSL 3.x.

--- aircast/src/castcore.c.orig	2024-02-01 09:13:45.000000000 +0000
+++ aircast/src/castcore.c
@@ -548,9 +548,6 @@ static void *CastPingThread(void *args)
 		crossthreads_sleep(1500);
 	}
 
-	// clear SSL error allocated memorry
-	ERR_remove_thread_state(NULL);
-
 	return NULL;
 }
 
@@ -695,8 +692,5 @@ static void *CastSocketThread(void *args
 		}
 	}
 
-	// clear SSL error allocated memorry
-	ERR_remove_thread_state(NULL);
-
 	return NULL;
 }
