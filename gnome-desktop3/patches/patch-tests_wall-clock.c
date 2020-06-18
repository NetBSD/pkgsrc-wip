$NetBSD$

Disable tests that rely on uselocale()

--- tests/wall-clock.c.orig	2020-04-29 01:53:29.099934300 +0000
+++ tests/wall-clock.c
@@ -30,6 +30,7 @@
 #define SPACE "  "
 #define EN_SPACE " "
 
+#if !defined(__NetBSD__)
 static void
 test_utf8_character (const char *utf8_char,
                      const char *non_utf8_fallback)
@@ -149,6 +150,7 @@ test_clock_format_setting (void)
 	uselocale (save_locale);
 	freelocale (locale);
 }
+#endif
 
 static gboolean
 on_notify_clock_timeout (gpointer user_data)
@@ -194,6 +196,7 @@ test_notify_clock (void)
 	g_object_unref (settings);
 }
 
+#if !defined(__NetBSD__)
 static void
 test_weekday_setting (void)
 {
@@ -245,6 +248,7 @@ test_weekday_setting (void)
 	uselocale (save_locale);
 	freelocale (locale);
 }
+#endif
 
 int
 main (int   argc,
@@ -254,11 +258,15 @@ main (int   argc,
 
 	g_test_init (&argc, &argv, NULL);
 
+#if !defined(__NetBSD__)
 	g_test_add_func ("/wall-clock/colon-vs-ratio", test_colon_vs_ratio);
 	g_test_add_func ("/wall-clock/space-vs-en-space", test_space_vs_en_space);
 	g_test_add_func ("/wall-clock/24h-clock-format", test_clock_format_setting);
+#endif
 	g_test_add_func ("/wall-clock/notify-clock", test_notify_clock);
+#if !defined(__NetBSD__)
 	g_test_add_func ("/wall-clock/weekday-setting", test_weekday_setting);
+#endif
 
 	return g_test_run ();
 }
