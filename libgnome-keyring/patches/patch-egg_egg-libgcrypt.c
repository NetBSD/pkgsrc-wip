$NetBSD$

--- egg/egg-libgcrypt.c.orig	2014-03-23 07:47:26.000000000 +0000
+++ egg/egg-libgcrypt.c
@@ -53,49 +53,8 @@ fatal_handler (gpointer unused, int unkn
 	g_log ("gcrypt", G_LOG_LEVEL_ERROR, "%s", msg);
 }
 
-static int
-glib_thread_mutex_init (void **lock)
-{
-#if GLIB_CHECK_VERSION(2,31,0)
-	*lock = g_slice_new (GMutex);
-	g_mutex_init (*lock);
-#else
-	*lock = g_mutex_new ();
-#endif
-	return 0;
-}
-
-static int
-glib_thread_mutex_destroy (void **lock)
-{
-#if GLIB_CHECK_VERSION(2,31,0)
-	g_mutex_clear (*lock);
-	g_slice_free (GMutex, *lock);
-#else
-	g_mutex_free (*lock);
-#endif
-	return 0;
-}
-
-static int
-glib_thread_mutex_lock (void **lock)
-{
-	g_mutex_lock (*lock);
-	return 0;
-}
-
-static int
-glib_thread_mutex_unlock (void **lock)
-{
-	g_mutex_unlock (*lock);
-	return 0;
-}
-
 static struct gcry_thread_cbs glib_thread_cbs = {
-	GCRY_THREAD_OPTION_USER, NULL,
-	glib_thread_mutex_init, glib_thread_mutex_destroy,
-	glib_thread_mutex_lock, glib_thread_mutex_unlock,
-	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
+	GCRY_THREAD_OPTION_USER
 };
 
 void
