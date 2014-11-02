$NetBSD: patch-source_linux_interface.c,v 1.1 2014/11/02 08:36:13 nsloss Exp $

Remove dependency on alsa.
--- source/linux/interface.c.orig	2008-06-25 02:44:42.000000000 +0000
+++ source/linux/interface.c
@@ -365,7 +365,9 @@ create_mainwindow (void)
   gtk_fixed_put (GTK_FIXED (fixed4), sndapicombo, 8, 8);
   gtk_widget_set_size_request (sndapicombo, 160, 32);
   gtk_combo_box_append_text (GTK_COMBO_BOX (sndapicombo), _("SDL"));
+#ifndef __NetBSD__
   gtk_combo_box_append_text (GTK_COMBO_BOX (sndapicombo), _("ALSA"));
+#endif
   gtk_combo_box_append_text (GTK_COMBO_BOX (sndapicombo), _("OSS"));
 
   label4 = gtk_label_new (_("Audio"));
