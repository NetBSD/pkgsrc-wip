$NetBSD$

LC_IDENTIFICATION is a GNU extension.
https://bugs.launchpad.net/lightdm/+bug/790186

--- liblightdm-gobject/language.c.orig	2018-09-05 01:33:31.000000000 +0000
+++ liblightdm-gobject/language.c
@@ -214,12 +214,16 @@ lightdm_language_get_name (LightDMLangua
         if (locale)
         {
             const gchar *current = setlocale (LC_ALL, NULL);
+#ifdef LC_IDENTICATION
             setlocale (LC_IDENTIFICATION, locale);
+#endif
             setlocale (LC_MESSAGES, "");
 
+#ifdef _NL_IDENTIFICATION_LANGUAGE
             const gchar *language_en = nl_langinfo (_NL_IDENTIFICATION_LANGUAGE);
             if (language_en && strlen (language_en) > 0)
                 priv->name = g_strdup (dgettext ("iso_639_3", language_en));
+#endif
 
             setlocale (LC_ALL, current);
         }
@@ -254,12 +258,16 @@ lightdm_language_get_territory (LightDML
         if (locale)
         {
             gchar *current = setlocale (LC_ALL, NULL);
+#ifdef LC_IDENTICATION
             setlocale (LC_IDENTIFICATION, locale);
+#endif
             setlocale (LC_MESSAGES, "");
 
+#ifdef _NL_IDENTIFICATION_TERRITORY
             gchar *country_en = nl_langinfo (_NL_IDENTIFICATION_TERRITORY);
             if (country_en && strlen (country_en) > 0 && g_strcmp0 (country_en, "ISO") != 0)
                 priv->territory = g_strdup (dgettext ("iso_3166", country_en));
+#endif
 
             setlocale (LC_ALL, current);
         }
