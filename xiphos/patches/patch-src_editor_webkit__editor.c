$NetBSD$

Disable the study pad. It only compiles with webkitgtk 1.x. Keep the
functions so that we can still compile everything else.

--- src/editor/webkit_editor.c.orig	2025-03-11 17:18:34.508841148 +0000
+++ src/editor/webkit_editor.c
@@ -29,7 +29,6 @@
 #include <ctype.h>
 
 #include <glib.h>
-#include <webkit/webkit.h>
 
 #include <libintl.h>
 #include <locale.h>
@@ -93,7 +92,6 @@ static void
 on_about_dialog_response(GtkDialog *dialog,
 			 gint response_id, gpointer user_data)
 {
-	gtk_widget_destroy(GTK_WIDGET(dialog));
 }
 
 /******************************************************************************
@@ -115,39 +113,21 @@ on_about_dialog_response(GtkDialog *dialog,
 G_MODULE_EXPORT void
 action_about_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	GtkWidget *about;
-	GdkPixbuf *about_logo;
-
-	about_logo = pixbuf_finder("xiphos-button-125.png", 0, NULL);
-	about = gtk_about_dialog_new();
-
-	g_signal_connect(about, "response",
-			 G_CALLBACK(on_about_dialog_response), NULL);
-	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(about), "WebKit editor, Xiphos");
-	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(about), (gchar *)VERSION);
-	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(about), "Replacement for gtkhtml editor");
-	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(about), about_logo);
-	set_window_icon(GTK_WINDOW(about));
-	gtk_widget_show(about);
 }
 
 G_MODULE_EXPORT void
 action_increase_indent_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('Indent', false, false);", e);
-	editor_insert_new_outline_level(e->toolitems.outline_level, e);
 }
 
 G_MODULE_EXPORT void
 action_decrease_indent_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('Outdent', false, false);", e);
 }
 
 G_MODULE_EXPORT void
 action_insert_rule_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_insert_html("<hr>", e);
 }
 
 G_MODULE_EXPORT void
@@ -158,141 +138,80 @@ action_insert_table_activate_cb(GtkWidget *widget, EDITOR *e)
 G_MODULE_EXPORT void
 action_insert_emoticon_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	// This is stupid, if we don't have emoticons working, then we sould
-	// remove the button users see.
-
-	//script = g_strdup ("document.execCommand('', null, \"\");");
 }
 
 G_MODULE_EXPORT void
 action_insert_image_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	gchar *filename = NULL;
-
-	GtkWidget *dialog = gtk_file_chooser_dialog_new("Select an image file",
-							NULL,
-							GTK_FILE_CHOOSER_ACTION_OPEN,
-#if GTK_CHECK_VERSION(3, 10, 0)
-							"_Cancel", GTK_RESPONSE_CANCEL,
-							"_OK", GTK_RESPONSE_ACCEPT,
-#else
-							GTK_STOCK_CANCEL,
-							GTK_RESPONSE_CANCEL,
-							GTK_STOCK_OK, GTK_RESPONSE_ACCEPT,
-#endif
-							NULL);
-
-	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
-		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
-		gchar *script = g_strdup_printf("document.execCommand('insertImage', null, '%s');", filename);
-		editor_execute_script(script, e);
-		g_free(script);
-	}
-
-	if (filename)
-		g_free(filename);
-	gtk_widget_destroy(dialog);
 }
 
 G_MODULE_EXPORT void
 action_insert_outline_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('insertHTML', null, \"<OL CLASS=L1><LI> </LI></OL> \");", e);
 }
 
 G_MODULE_EXPORT void
 action_justify_right_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('justifyright', false, false);", e);
 }
 
 G_MODULE_EXPORT void
 action_justify_left_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('justifyleft', false, false);", e);
 }
 
 G_MODULE_EXPORT void
 action_justify_center_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('justifycenter', false, false);", e);
 }
 
 G_MODULE_EXPORT void
 action_justify_full_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('justifyfull', false, false);", e);
 }
 
 G_MODULE_EXPORT void
 action_bold_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	if (buttons_state.nochange)
-		return;
-
-	editor_execute_script("document.execCommand('bold',false,false);", e);
 }
 
 G_MODULE_EXPORT void
 action_italic_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	//extern BUTTONS_STATE buttons_state;
-	if (buttons_state.nochange)
-		return;
-
-	editor_execute_script("document.execCommand('italic',false,false);", e);
 }
 
 G_MODULE_EXPORT void
 action_undo_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('undo',false,false);", e);
 }
 
 G_MODULE_EXPORT void
 action_redo_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_execute_script("document.execCommand('redo',false,false);", e);
 }
 
 G_MODULE_EXPORT void
 action_underline_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	//extern BUTTONS_STATE buttons_state;
-	if (buttons_state.nochange)
-		return;
-
-	editor_execute_script("document.execCommand('underline', false, false);", e);
 }
 
 G_MODULE_EXPORT void
 action_strikethrough_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	//extern BUTTONS_STATE buttons_state;
-	if (buttons_state.nochange)
-		return;
-
-	editor_execute_script("document.execCommand('strikethrough', false, false);", e);
 }
 
 G_MODULE_EXPORT void action_cut_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_cut(e);
 }
 
 G_MODULE_EXPORT void
 action_copy_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	if (editor_copy(e))
-		XI_message(("%s", "copy success"));
-	else
-		XI_message(("%s", "copy failed"));
 }
 
 G_MODULE_EXPORT void
 action_paste_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_paste(e);
 }
 
 G_MODULE_EXPORT void
@@ -303,737 +222,93 @@ action_delete_activate_cb(GtkWidget *widget, EDITOR *e)
 G_MODULE_EXPORT void
 action_delete_item_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	if (e->studypad)
-		return;
-
-	gchar *buf = 
-		g_strdup_printf("<span weight=\"bold\" size=\"larger\">%s %s?</span>",
-				_("Are you sure you want to delete the note for"), e->key);
-
-	if (gui_yes_no_dialog(buf,
-#if GTK_CHECK_VERSION(3, 10, 0)
-			      "dialog-warning"
-#else
-			      GTK_STOCK_DIALOG_WARNING
-#endif
-			      )) {
-
-		main_delete_note(e->module, e->key);
-
-		/* new empty document from template */
-		gchar *fname = g_build_filename(settings.gSwordDir, "studypad.spt", NULL);
-		XI_message(("action delete item [%s]", fname));
-		gchar *text = inhale_text_from_file(fname);
-		g_free(fname);
-
-		if (text && strlen(text)) {
-			webkit_web_view_load_string((WebKitWebView *)
-						    e->html_widget,
-						    text,
-						    "application/xhtml+xml", "utf_8",
-						    "file://");
-		}
-		if (text)
-			g_free(text);
-	}
-
-	g_free(buf);
-	e->is_changed = FALSE;
 }
 
 void set_button_state(BUTTONS_STATE state, EDITOR *e)
 {
-#if GTK_CHECK_VERSION(3, 4, 0)
-	GdkRGBA rgba;
-#else
-	GdkColor color;
-#endif
-	gtk_toggle_tool_button_set_active(e->toolitems.bold, state.bold);
-	gtk_toggle_tool_button_set_active(e->toolitems.italic, state.italic);
-	gtk_toggle_tool_button_set_active(e->toolitems.underline, state.underline);
-	gtk_toggle_tool_button_set_active(e->toolitems.strike, state.strike);
-	gtk_combo_box_set_active((GtkComboBox *)e->toolitems.cb, state.style);
-
-	if (state.color) {
-		XI_message(("state.color: %s", state.color));
-#if GTK_CHECK_VERSION(3, 4, 0)
-		if (gdk_rgba_parse(&rgba, state.color))
-			gtk_color_chooser_set_rgba((GtkColorChooser *)
-						   e->toolitems.color,
-						   &rgba);
-#else
-		if (gdk_color_parse(state.color, &color))
-			gtk_color_button_set_color((GtkColorButton *)
-						   e->toolitems.color,
-						   &color);
-#endif
-	}
 }
 
 G_MODULE_EXPORT void
 colorbutton1_color_set_cb(GtkColorButton *widget, EDITOR *e)
 {
-#if GTK_CHECK_VERSION(3, 4, 0)
-	GdkRGBA color;
-#else
-	GdkColor color;
-#endif
-	gchar *color_str;
-	gchar *forecolor = NULL;
-
-#if GTK_CHECK_VERSION(3, 4, 0)
-	gtk_color_chooser_get_rgba((GtkColorChooser *)widget, &color);
-	color_str = gdk_rgba_to_string(&color);
-#else
-	gtk_color_button_get_color((GtkColorButton *)widget, &color);
-	/* FIXME: ugly need something better */
-	color_str = g_strdup_printf("rgb(%u,%u,%u)", color.red >> 8, color.green >> 8, color.blue >> 8);
-#endif
-	forecolor = g_strdup_printf("document.execCommand('forecolor', null, '%s');", color_str);
-	editor_execute_script(forecolor, e);
-	g_free(forecolor);
-	g_free(color_str);
 }
 
 G_MODULE_EXPORT void
 colorbutton_highlight_color_set_cb(GtkColorButton *widget, EDITOR *e)
 {
-
-#if GTK_CHECK_VERSION(3, 4, 0)
-	GdkRGBA color;
-#else
-	GdkColor color;
-#endif
-	gchar *color_str;
-	gchar *highlightcolor = NULL;
-
-#if GTK_CHECK_VERSION(3, 4, 0)
-	gtk_color_chooser_get_rgba((GtkColorChooser *)widget, &color);
-	color_str = gdk_rgba_to_string(&color);
-#else
-	gtk_color_button_get_color((GtkColorButton *)widget, &color);
-	/* FIXME: ugly need something better */
-	color_str = g_strdup_printf("rgb(%u,%u,%u)", color.red >> 8, color.green >> 8, color.blue >> 8);
-#endif
-	highlightcolor = g_strdup_printf("document.execCommand('backColor', null, '%s');", color_str);
-	editor_execute_script(highlightcolor, e);
-	g_free(highlightcolor);
-	g_free(color_str);
-}
-
-static gchar *get_font_size_from_name(GString *fontname)
-{
-	gchar buf[80];
-	gint len, i = 0, j = 0;
-
-	len = fontname->len;
-	XI_message(("\nlength: %d\n", len));
-	for (i = 0; (i < 79 && i < len); i++) {
-		if (isdigit(fontname->str[i])) {
-			XI_message(("\n\nfontname->str[i]: %c",
-				    fontname->str[i]));
-			buf[j] = fontname->str[i];
-			buf[j + 1] = '\0';
-			j++;
-		}
-	}
-	return g_strdup(buf);
 }
 
-G_MODULE_EXPORT void
-action_font_activate_cb(GtkWidget *widget, EDITOR *e)
-{
-	GtkWidget *dialog;
-	gchar *selected_text = NULL;
-	gchar *size = NULL;
-#if GTK_CHECK_VERSION(3, 2, 0)
-	dialog = gtk_font_chooser_dialog_new("Select font", NULL);
-	gtk_font_chooser_set_font((GtkFontChooser *)dialog,
-#else
-	dialog = gtk_font_selection_dialog_new("Select font");
-	gtk_font_selection_dialog_set_font_name((GtkFontSelectionDialog *)
-						dialog,
-#endif
-				  "Droid Sans 14");
-
-	if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
-#if GTK_CHECK_VERSION(3, 2, 0)
-		const gchar *fontname = gtk_font_chooser_get_font((GtkFontChooser *)dialog);
-#else
-		const gchar *fontname = gtk_font_selection_dialog_get_font_name((GtkFontSelectionDialog *)dialog);
-#endif
-		GString *name = g_string_new(fontname);
-		size = get_font_size_from_name(name);
-		g_string_free(name, TRUE);
-
-		selected_text = editor_get_selected_text(e);
-#if GTK_CHECK_VERSION(3, 2, 0)
-		PangoFontDescription *font_description =
-			gtk_font_chooser_get_font_desc((GtkFontChooser *)
-						       dialog);
-		fontname = pango_font_description_get_family(font_description);
-#else
-		PangoFontDescription *font_description =
-			pango_font_description_from_string(fontname);
-		fontname = pango_font_description_get_family(font_description);
-#endif
-
-		gchar *script = g_strdup_printf("<SPAN STYLE=\"font-family:%s;font-size:%spx;\">%s</SPAN>",
-						fontname, size, selected_text);
-
-		editor_insert_html(script, e);
-		g_free(script);
-	}
-	if (size)
-		g_free(size);
-	if (selected_text)
-		g_free(selected_text);
-	gtk_widget_destroy(dialog);
-}
 
 G_MODULE_EXPORT void
 find_replace_response_cb(GtkDialog *dialog, gint response_id, EDITOR *e)
 {
-	switch (response_id) {
-	case GTK_RESPONSE_CANCEL:
-		gtk_widget_hide(find_dialog.window);
-		break;
-	case 1:
-		editor_find_string((gchar *)
-				   gtk_entry_get_text(GTK_ENTRY(find_dialog.find_entry)),
-				   e);
-		break;
-	case 2:
-		editor_replace_string((gchar *)
-				      gtk_entry_get_text(GTK_ENTRY(find_dialog.find_entry)),
-				      (gchar *)
-				      gtk_entry_get_text(GTK_ENTRY(find_dialog.replace_entry)),
-				      e);
-		break;
-	default:
-		gtk_widget_hide(find_dialog.window);
-		break;
-	}
 }
 
 G_MODULE_EXPORT void
 action_find_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	gtk_widget_show(find_dialog.window);
-	gtk_widget_hide(find_dialog.box_replace);
-	gtk_widget_hide(find_dialog.button_replace);
 }
 
 G_MODULE_EXPORT void
 action_replace_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	gtk_widget_show(find_dialog.window);
-	gtk_widget_show(find_dialog.box_replace);
-	gtk_widget_show(find_dialog.button_replace);
-}
-
-static void handle_error(GError **error)
-{
-	if (*error != NULL) {
-		g_warning("%s", (*error)->message);
-		g_clear_error(error);
-	}
-}
-
-static void do_exit(EDITOR *e)
-{
-	if (e->filename) {
-		g_free(e->filename);
-	}
-	if (e->module) {
-		g_free(e->module);
-	}
-	if (e->key) {
-		g_free(e->key);
-	}
-	if (e->window)
-		gtk_widget_destroy(e->window);
-	g_free(e);
-}
-
-static void recent_item_cb(GtkRecentChooser *chooser, EDITOR *e)
-{
-	gchar *file_uri = gtk_recent_chooser_get_current_uri(chooser);
-
-	XI_message(("file_uri: %s", file_uri));
-	if (e->filename)
-		g_free(e->filename);
-	e->filename = g_strdup(file_uri);
-
-	//editor_open_recent (file_uri, e);
-	_load_file(e, file_uri);
-	xml_set_value("Xiphos", "studypad", "lastfile", e->filename);
-	settings.studypadfilename = xml_get_value("studypad", "lastfile");
-
-	change_window_title(e->window, e->filename);
-}
-
-static void change_window_title(GtkWidget *window, const gchar *window_title)
-{
-	gtk_window_set_title(GTK_WINDOW(window), window_title);
-}
-
-static GtkPrintOperationResult
-print(WebKitWebView *html, GtkPrintOperationAction action)
-{
-	GtkPrintOperation *operation;
-	GtkPrintOperationResult result;
-	GError *error = NULL;
-	WebKitWebFrame *frame;
-
-	frame = webkit_web_view_get_main_frame(html);
-	operation = gtk_print_operation_new();
-
-	result = webkit_web_frame_print_full(frame, operation, action, &error);
-
-	g_object_unref(operation);
-	handle_error(&error);
-
-	return result;
-}
-
-static gint open_dialog(EDITOR *e)
-{
-	GtkWidget *dialog;
-	gint response;
-
-	dialog = gtk_file_chooser_dialog_new(_("Open"), GTK_WINDOW(e->window),
-					     GTK_FILE_CHOOSER_ACTION_OPEN,
-#if GTK_CHECK_VERSION(3, 10, 0)
-					     "_Cancel", GTK_RESPONSE_CANCEL,
-					     "_Open", GTK_RESPONSE_ACCEPT,
-#else
-					     GTK_STOCK_CANCEL,
-					     GTK_RESPONSE_CANCEL,
-					     GTK_STOCK_OPEN,
-					     GTK_RESPONSE_ACCEPT,
-#endif
-					     NULL);
-
-	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), settings.studypaddir);
-
-	response = gtk_dialog_run(GTK_DIALOG(dialog));
-
-	if (response == GTK_RESPONSE_ACCEPT) {
-		gchar *new_filename;
-
-		new_filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
-		_load_file(e, new_filename);
-		g_free(new_filename);
-	}
-
-	gtk_widget_destroy(dialog);
-
-	return response;
 }
 
 G_MODULE_EXPORT void action_print_cb(GtkAction *action, EDITOR *e)
 {
-	print(WEBKIT_WEB_VIEW(e->html_widget),
-	      GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG);
 }
 
 G_MODULE_EXPORT void action_print_preview_cb(GtkAction *action, EDITOR *e)
 {
-	print(WEBKIT_WEB_VIEW(e->html_widget),
-	      GTK_PRINT_OPERATION_ACTION_PREVIEW);
 }
 
 G_MODULE_EXPORT void action_quit_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	delete_event(NULL, NULL, e);
 }
 
 G_MODULE_EXPORT void action_open_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	open_dialog(e);
 }
 
 G_MODULE_EXPORT void action_save_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	switch (e->type) {
-	case STUDYPAD_EDITOR:
-		_save_file(e);
-		break;
-	case NOTE_EDITOR:
-		_save_note(e);
-		break;
-	case BOOK_EDITOR:
-		_save_book(e);
-		break;
-	default:
-		XI_message(("\naction_save_cb oops!\n"));
-		break;
-	}
 }
 
 G_MODULE_EXPORT void action_new_activate_cb(GtkWidget *widget, EDITOR *e)
 { /* for studypad only */
-	gchar *filename = NULL;
-
-	if (e->is_changed)
-		ask_about_saving(e);
-
-	filename = g_strdup_printf("%s/%s", settings.gSwordDir, "studypad.spt");
-
-	_load_file(e, filename);
-
-	if (e->filename)
-		g_free(e->filename);
-	e->filename = g_strdup(_("Untitled document"));
-
-	xml_set_value("Xiphos", "studypad", "lastfile", e->filename);
-	settings.studypadfilename = xml_get_value("studypad", "lastfile");
-	change_window_title(e->window, e->filename);
-	e->is_changed = TRUE;
 }
 
 G_MODULE_EXPORT void
 action_insert_sword_link_activate_cb(GtkWidget *widget, gpointer data)
 {
-	editor_link_dialog(data); //editor_insert_sword_link();
 }
 
 G_MODULE_EXPORT void
 action_insert_link_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	editor_link_dialog(e);
 }
 
 G_MODULE_EXPORT void
 action_save_as_activate_cb(GtkWidget *widget, EDITOR *e)
 {
-	if (e->filename)
-		g_free(e->filename);
-	e->filename = NULL;
-	_save_file(e);
 }
 
 G_MODULE_EXPORT void combo_box_changed_cb(GtkComboBox *widget, EDITOR *e)
 {
-	gchar *script = NULL;
-	gint choice = gtk_combo_box_get_active(widget);
-	/* we need the line of text where the cursor is */
-	//extern BUTTONS_STATE buttons_state;
-
-	if (buttons_state.nochange)
-		return;
-
-	switch (choice) {
-	case 0: /* Normal  */
-		script = "document.execCommand('formatBlock', false, \"div\");";
-		break;
-
-	case 1: /* H1  */
-		script = "document.execCommand('formatBlock', null, \"H1\");";
-		break;
-
-	case 2: /* H2 */
-		script = "document.execCommand('formatBlock', null, \"H2\");";
-		break;
-
-	case 3: /* H3  */
-		script = "document.execCommand('formatBlock', null, \"H3\");";
-		break;
-
-	case 4: /* H4  */
-		script = "document.execCommand('formatBlock', null, \"H4\");";
-		break;
-
-	case 5: /* H5 */
-		script = "document.execCommand('formatBlock', null, \"H5\");";
-		break;
-
-	case 6: /* H6  */
-		script = "document.execCommand('formatBlock', null, \"H6\");";
-		break;
-
-	case 7: /* Address  */
-		script = "document.execCommand('formatBlock', null, \"ADDRESS\");";
-		break;
-
-	case 8: /* Preformatted  */
-		script = "document.execCommand('formatBlock', null, \"PRE\");";
-		break;
-
-	case 9: /* Bulleted List  insertUnorderedList */
-		script = "document.execCommand('insertUnorderedList', null, \"\");";
-		break;
-
-	case 10: /* Roman Numeral List  */
-		script = "document.execCommand('insertHTML', null, \"<OL type=I><LI> </LI></OL> \");";
-		break;
-
-	case 11: /* Numbered List  insertOrderedList */
-		script = "document.execCommand('insertOrderedList', null, \"\");";
-		break;
-
-	case 12: /* Alphabetical List  */
-		script = "document.execCommand('insertHTML', null, \"<OL type=A><LI> </LI></OL> \");";
-		break;
-
-	default:
-		break;
-	}
-
-	if (script) {
-		XI_message(("%s", script));
-		editor_execute_script(script, e);
-	}
-}
-
-/* need note toolbars when type is note */
-static GtkWidget *editor_new(const gchar *title, EDITOR *e)
-{
-	GtkWidget *window;
-	GtkWidget *scrollwindow;
-	GtkWidget *statusbar;
-	GtkBuilder *builder;
-	gchar *gbuilder_file;
-	GError *error = NULL;
-	GtkMenuItem *item;
-	GtkWidget *recent_item;
-
-	buttons_state.nochange = 1;
-
-	gbuilder_file = gui_general_user_file(
-#ifdef USE_GTK_3
-	    "gtk_webedit.ui"
-#else
-	    "gtk2_webedit.ui"
-#endif
-	    ,
-	    FALSE);
-	builder = gtk_builder_new();
-
-	if (!gtk_builder_add_from_file(builder, gbuilder_file, &error)) {
-		g_warning("Couldn't load builder file: %s",
-			  error->message);
-		g_error_free(error);
-	}
-
-	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
-	e->window = window;
-	gtk_window_set_title(GTK_WINDOW(window), title);
-
-	statusbar = GTK_WIDGET(gtk_builder_get_object(builder, "statusbar1"));
-	gtk_widget_hide(statusbar);
-
-	e->toolitems.outline_level = 0;
-	e->toolitems.bold = GTK_TOGGLE_TOOL_BUTTON(gtk_builder_get_object(builder, "toolbutton_bold"));
-	e->toolitems.italic = GTK_TOGGLE_TOOL_BUTTON(gtk_builder_get_object(builder, "toolbutton_italic"));
-	e->toolitems.underline = GTK_TOGGLE_TOOL_BUTTON(gtk_builder_get_object(builder, "toolbuttonunderline"));
-	e->toolitems.strike = GTK_TOGGLE_TOOL_BUTTON(gtk_builder_get_object(builder, "toolbutton_strikethrough"));
-	e->toolitems.open = GTK_TOOL_BUTTON(gtk_builder_get_object(builder, "toolbutton_open"));
-	e->toolitems.newdoc = GTK_TOOL_BUTTON(gtk_builder_get_object(builder, "toolbutton_new"));
-	e->toolitems.deletedoc = GTK_TOOL_BUTTON(gtk_builder_get_object(builder, "toolbutton_delete"));
-	e->toolitems.color = GTK_COLOR_BUTTON(gtk_builder_get_object(builder, "colorbutton1"));
-	e->toolitems.cb = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "comboboxtext1"));
-
-	gtk_combo_box_set_active((GtkComboBox *)e->toolitems.cb, 0);
-
-	item = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menuitem_recent"));
-
-	switch (e->type) {
-	case STUDYPAD_EDITOR:
-		gtk_widget_hide(GTK_WIDGET(e->toolitems.deletedoc));
-
-		recent_item = gtk_recent_chooser_menu_new();
-		g_signal_connect(G_OBJECT(recent_item), "item-activated",
-				 G_CALLBACK(recent_item_cb), e);
-		gtk_menu_item_set_submenu(item, recent_item);
-		break;
-	case NOTE_EDITOR:
-		gtk_widget_hide(GTK_WIDGET(e->toolitems.open));
-		gtk_widget_hide(GTK_WIDGET(e->toolitems.newdoc));
-		gtk_widget_hide(GTK_WIDGET(item));
-		break;
-	case BOOK_EDITOR:
-		gtk_widget_hide(GTK_WIDGET(e->toolitems.open));
-		gtk_widget_hide(GTK_WIDGET(e->toolitems.newdoc));
-		gtk_widget_hide(GTK_WIDGET(item));
-		break;
-	}
-
-	e->navbar_box = GTK_WIDGET(gtk_builder_get_object(builder, "box_navbar"));
-	e->box = GTK_WIDGET(gtk_builder_get_object(builder, "vbox1"));
-
-	scrollwindow = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledwindow1"));
-	create_editor_window(scrollwindow, e);
-	e->is_changed = FALSE;
-
-	/* This is important */
-	gtk_builder_connect_signals(builder, (EDITOR *)e);
-
-	find_dialog.window = GTK_WIDGET(gtk_builder_get_object(builder, "dialog_find_replace"));
-	find_dialog.find_entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
-	find_dialog.replace_entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
-	find_dialog.box_replace = GTK_WIDGET(gtk_builder_get_object(builder, "box4"));
-	find_dialog.button_replace = GTK_WIDGET(gtk_builder_get_object(builder, "button_replace"));
-
-	g_object_unref(builder);
-
-	return window;
-}
-
-static void _save_note(EDITOR *e)
-{
-	GString *data = g_string_new("");
-
-	editor_get_document_content(data, e);
-	main_save_note(e->module, e->key, data->str);
-	e->is_changed = FALSE;
-	g_string_free(data, TRUE);
-}
-
-static void _save_book(EDITOR *e)
-{
-	GString *data = g_string_new("");
-
-	editor_get_document_content(data, e);
-	main_treekey_save_book_text(e->module, e->key, data->str);
-	e->is_changed = FALSE;
-	g_string_free(data, TRUE);
-}
-
-static void _save_file(EDITOR *e)
-{
-	GtkRecentManager *rm = NULL;
-	GString *data = g_string_new("");
-
-	editor_get_document_content(data, e);
-	XI_message(("%s", data->str));
-
-	if (!e->filename || (0 == g_strcmp0("Untitled document", e->filename)) || g_strrstr(e->filename, ".spt")) {
-		GtkWidget *dialog = gtk_file_chooser_dialog_new("Save as",		      //const gchar *title,
-								NULL,			      //GtkWindow *parent,
-								GTK_FILE_CHOOSER_ACTION_SAVE, //GtkFileChooserAction action,
-#if GTK_CHECK_VERSION(3, 10, 0)
-								"_OK",
-								GTK_RESPONSE_OK,
-								"_Cancel",
-								GTK_RESPONSE_CANCEL,
-#else
-								GTK_STOCK_OK,
-								GTK_RESPONSE_OK,
-								GTK_STOCK_CANCEL,
-								GTK_RESPONSE_CANCEL,
-#endif
-								NULL);
-		gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);
-
-		gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog),
-						    settings.studypaddir);
-		if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
-			gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
-			e->filename = g_strdup(filename);
-			GFile *gfile = g_file_parse_name(filename);
-			g_file_replace_contents(gfile, data->str, data->len, NULL, TRUE, G_FILE_CREATE_NONE, NULL, NULL, NULL); //GError **error
-		}
-		change_window_title(e->window, e->filename);
-		gtk_widget_destroy(dialog);
-
-	} else {
-
-		GFile *gfile = g_file_parse_name(e->filename);
-		g_file_replace_contents(gfile, data->str, data->len, NULL, TRUE, G_FILE_CREATE_NONE, NULL, NULL, NULL); //GError **error
-	}
-
-	rm = gtk_recent_manager_get_default();
-	gtk_recent_manager_add_item(rm, e->filename);
-
-	e->is_changed = FALSE;
-	g_string_free(data, TRUE);
-}
-
-static void _load_file(EDITOR *e, const gchar *filename)
-{
-	char *text = NULL;
-	GtkRecentManager *rm = NULL;
-
-	rm = gtk_recent_manager_get_default();
-	gtk_recent_manager_add_item(rm, filename);
-
-	if (e->filename)
-		g_free(e->filename);
-	e->filename = g_strdup(filename);
-
-	XI_message(("_load_file filename: %s", filename));
-
-	xml_set_value("Xiphos", "studypad", "lastfile", e->filename);
-	settings.studypadfilename = xml_get_value("studypad", "lastfile");
-
-	change_window_title(e->window, e->filename);
-	text = inhale_text_from_file(!strncmp(filename, "file:", 5)
-					 ? filename + 5
-					 : filename);
-
-	XI_message(("web view load string [%s]", text));
-	webkit_web_view_load_string(WEBKIT_WEB_VIEW(e->html_widget),
-				    text, "application/xhtml+xml", "utf_8", "file://");
-
-	g_free(text);
-	e->is_changed = FALSE;
 }
 
 gboolean editor_is_dirty(EDITOR *e)
 {
-	return e->is_changed;
+	return FALSE;
 }
 
 void editor_save_book(EDITOR *e)
 {
-	if (editor_is_dirty(e))
-		_save_book(e);
 }
 
 /* save if needed is done in treeky-editor.c before calling editor_load_book() */
 void editor_load_book(EDITOR *e)
 {
-	gchar *title = NULL, *text = NULL;
-
-	if (!g_ascii_isdigit(e->key[0]))
-		return; /* make sure is a number (offset) */
-
-	XI_message(("book: %s\noffset :%s", e->module, e->key));
-
-	if (atol(e->key) != 0)
-		text = main_get_book_raw_text(e->module, e->key);
-	else
-		text = g_strdup(e->module);
-
-	if ((text == NULL) || strlen(text) == 0) {
-		if (text)
-			g_free(text);
-
-		/* new empty document from template */
-		gchar *fname = g_build_filename(settings.gSwordDir, "studypad.spt", NULL);
-		XI_message(("editor load BOOK [%s]", fname));
-		text = inhale_text_from_file(fname);
-		g_free(fname);
-	}
-
-	if (text && strlen(text)) {
-		webkit_web_view_load_string((WebKitWebView *)
-					    e->html_widget,
-					    text,
-					    "application/xhtml+xml", "utf_8",
-					    "file://");
-	}
-
-	if (text)
-		g_free(text);
-
-	title = g_strdup_printf("%s", e->module);
-	change_window_title(e->window, title);
-	g_free(title);
-
-	e->is_changed = FALSE;
 }
 
 /******************************************************************************
@@ -1054,281 +329,19 @@ void editor_load_book(EDITOR *e)
 
 void editor_sync_with_main(void)
 {
-	GList *tmp = NULL;
-
-	tmp = g_list_first(editors_all);
-	while (tmp != NULL) {
-		EDITOR *e = (EDITOR *)tmp->data;
-
-		switch (e->type) {
-		case STUDYPAD_EDITOR:
-		case BOOK_EDITOR:
-			break;
-		case NOTE_EDITOR:
-			if (e->sync)
-				editor_load_note(e, NULL,
-						 settings.currentverse);
-			break;
-		}
-		tmp = g_list_next(tmp);
-	}
 }
 
 void
 editor_load_note(EDITOR *e, const gchar *module_name, const gchar *key)
 {
-	gchar *title = NULL, *text = NULL;
-
-	if (e->is_changed)
-		_save_note(e);
-
-	if (module_name) {
-		if (e->module)
-			g_free(e->module);
-		e->module = g_strdup(module_name);
-	}
-	if (key) {
-		if (e->key)
-			g_free(e->key);
-		e->key = g_strdup(key);
-	}
-
-	text = main_get_raw_text((gchar *)e->module, (gchar *)e->key);
-
-	if ((text == NULL) || strlen(text) == 0) {
-		if (text)
-			g_free(text);
-
-		/* new empty document from template */
-		gchar *fname = g_build_filename(settings.gSwordDir, "studypad.spt", NULL);
-		XI_message(("editor load NOTE [%s]", fname));
-		text = inhale_text_from_file(fname);
-		g_free(fname);
-	}
-
-	if (text && strlen(text)) {
-		webkit_web_view_load_string((WebKitWebView *)
-					    e->html_widget,
-					    text,
-					    "application/xhtml+xml", "utf_8",
-					    "file://");
-	}
-
-	e->is_changed = FALSE;
-	if (e->type == NOTE_EDITOR) {
-		e->navbar.valid_key = TRUE;
-		main_navbar_versekey_set(e->navbar, e->key);
-	}
-
-	if (text)
-		g_free(text);
-
-	title = g_strdup_printf("%s - %s", e->module, e->key);
-	change_window_title(e->window, title);
-	g_free(title);
 }
 
 G_MODULE_EXPORT int
 delete_event(GtkWidget *widget, GdkEvent *event, EDITOR *e)
 {
-	if (e->is_changed) {
-		switch (ask_about_saving(e)) {
-		case GS_YES: /* exit saving */
-			break;
-
-		case GS_NO: /* exit without saving */
-			break;
-
-		case GS_CANCEL:
-			return TRUE;
-		}
-	}
-	editors_all = g_list_remove(editors_all, e);
-	do_exit(e);
 	return FALSE;
 }
 
-gint ask_about_saving(EDITOR *e)
-{
-	gint test;
-	GS_DIALOG *info;
-	gchar *buf = NULL;
-	gchar *buf1 = NULL;
-	gchar *buf2 = NULL;
-	gchar *buf3 = NULL;
-	gint retval = FALSE;
-
-	switch (e->type) {
-	case BOOK_EDITOR:
-	case NOTE_EDITOR:
-		info = gui_new_dialog();
-		info->stock_icon =
-#if GTK_CHECK_VERSION(3, 10, 0)
-		    "dialog-warning";
-#else
-		    GTK_STOCK_DIALOG_WARNING;
-#endif
-
-		buf = g_strdup_printf("%s: %s", e->module, e->key);
-		buf1 = _("Save the changes to document");
-		buf2 = _("before closing?");
-		buf3 = g_strdup_printf("<span weight=\"bold\" size=\"larger\">%s %s %s</span>",
-				       buf1, buf, buf2);
-		info->label_top = buf3;
-		info->label2 = _("If you don't save, changes will be permanently lost.");
-		info->save = TRUE;
-		info->cancel = TRUE;
-		info->no_save = TRUE;
-
-		test = gui_alert_dialog(info);
-		retval = test;
-
-		if (test == GS_YES) {
-			if (e->type == NOTE_EDITOR) {
-				/* save notes and prayer lists */
-				_save_note(e);
-
-			} else {
-				/* save notes and prayer lists */
-				_save_book(e);
-			}
-		}
-		g_free(info);
-		g_free(buf);
-		g_free(buf3);
-		break;
-
-	case STUDYPAD_EDITOR:
-		info = gui_new_dialog();
-		info->stock_icon =
-#if GTK_CHECK_VERSION(3, 10, 0)
-		    "dialog-warning";
-#else
-		    GTK_STOCK_DIALOG_WARNING;
-#endif
-		if (settings.studypadfilename)
-			buf = settings.studypadfilename;
-		else
-			buf = N_("File");
-		buf1 = _("Save the changes to document");
-		buf2 = _("before closing?");
-		buf3 = g_strdup_printf("<span weight=\"bold\" size=\"larger\">%s %s %s</span>",
-				       buf1, buf, buf2);
-		info->label_top = buf3;
-		info->label2 = _("If you don't save, changes will be permanently lost.");
-		info->save = TRUE;
-		info->cancel = TRUE;
-		info->no_save = TRUE;
-
-		test = gui_alert_dialog(info);
-		retval = test;
-		if (test == GS_YES) {
-			_save_file(e);
-		}
-		g_free(info);
-		g_free(buf3);
-		break;
-	}
-	sync_windows();
-	return retval;
-}
-
-static gint _create_new(const gchar *filename, const gchar *key,
-			gint editor_type)
-{
-	EDITOR *editor;
-	GtkWidget *toolbar_nav = NULL;
-
-	editor = g_new(EDITOR, 1);
-	editor->html_widget = NULL;
-	editor->sync = FALSE;
-	editor->type = editor_type;
-
-	switch (editor_type) {
-	case STUDYPAD_EDITOR:
-		editor->studypad = TRUE;
-		editor->bookeditor = FALSE;
-		editor->noteeditor = FALSE;
-		editor->module = NULL;
-		editor->key = NULL;
-		editor->filename = NULL;
-		widgets.studypad_dialog = editor_new(_("StudyPad"), editor);
-
-		if (filename) {
-			editor->filename = g_strdup(filename);
-			_load_file(editor, g_strdup(filename));
-		}
-		break;
-	case NOTE_EDITOR:
-		editor->noteeditor = TRUE;
-		editor->bookeditor = FALSE;
-		editor->studypad = FALSE;
-		editor->filename = NULL;
-		editor->module = g_strdup(filename);
-		editor->key = g_strdup(key);
-		editor->navbar.key = NULL;
-		editor_new(_("Note Editor"), editor);
-
-		toolbar_nav = gui_navbar_versekey_editor_new(editor);
-		gtk_widget_show(toolbar_nav);
-		gtk_box_pack_start(GTK_BOX(editor->navbar_box),
-				   GTK_WIDGET(toolbar_nav), FALSE, TRUE,
-				   0);
-
-		editor_load_note(editor, NULL, NULL);
-		break;
-	case BOOK_EDITOR:
-		editor->bookeditor = TRUE;
-		editor->noteeditor = FALSE;
-		editor->studypad = FALSE;
-		editor->filename = NULL;
-		editor->module = g_strdup(filename);
-		editor->key = g_strdup(key);
-		editor_new(_("Prayer List/Journal Editor"), editor);
-
-		GtkWidget *box;
-		UI_VBOX(box, FALSE, 0);
-		gtk_widget_show(box);
-		GtkWidget *hpaned1 = UI_HPANE();
-		gtk_widget_show(hpaned1);
-		gtk_paned_pack2(GTK_PANED(hpaned1), box, TRUE, TRUE);
-
-		GtkWidget *scrollbar = gtk_scrolled_window_new(NULL, NULL);
-		gtk_widget_show(scrollbar);
-		gtk_paned_pack1(GTK_PANED(hpaned1), GTK_WIDGET(scrollbar),
-				TRUE, TRUE);
-		gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollbar),
-					       GTK_POLICY_AUTOMATIC,
-					       GTK_POLICY_AUTOMATIC);
-		gtk_scrolled_window_set_shadow_type((GtkScrolledWindow *)
-						    scrollbar,
-						    settings.shadow_type);
-
-		editor->treeview = gui_create_editor_tree(editor);
-		gtk_widget_show(editor->treeview);
-		gtk_container_add(GTK_CONTAINER(scrollbar),
-				  editor->treeview);
-		gtk_paned_set_position(GTK_PANED(hpaned1), 125);
-		gtk_tree_view_expand_all((GtkTreeView *)editor->treeview);
-// then we should expand on the item to which we've opened for edit.
-
-#if GTK_CHECK_VERSION(3, 10, 0)
-		gtk_container_add(GTK_CONTAINER(box), editor->box);
-#else
-		gtk_widget_reparent(editor->box, box);
-#endif
-
-		gtk_container_add(GTK_CONTAINER(editor->window), hpaned1);
-
-		editor_load_book(editor);
-
-		break;
-	}
-	editor->is_changed = FALSE;
-	editors_all = g_list_append(editors_all, (EDITOR *)editor);
-	return 1;
-}
-
 /******************************************************************************
  * Name
  *   editor_create_new
@@ -1348,85 +361,11 @@ static gint _create_new(const gchar *filename, const gchar *key,
 gint editor_create_new(const gchar *filename, const gchar *key,
 		       gint editor_type)
 {
-	GList *tmp = NULL;
-
-	tmp = g_list_first(editors_all);
-	while (tmp != NULL) {
-		EDITOR *e = (EDITOR *)tmp->data;
-		switch (editor_type) {
-		case STUDYPAD_EDITOR:
-			if (e->studypad) {
-				if (editor_is_dirty(e))
-					_save_file(e);
-				if (e->filename)
-					g_free(e->filename);
-				e->filename = g_strdup(filename);
-				gtk_widget_show(e->window);
-				gdk_window_raise(gtk_widget_get_parent_window(GTK_WIDGET(e->window)));
-
-				_load_file(e, g_strdup(filename));
-				return 1;
-			}
-			break;
-		case NOTE_EDITOR:
-			if (!e->noteeditor)
-				break;
-			if (editor_is_dirty(e))
-				_save_note(e);
-			if (e->module)
-				g_free(e->module);
-			e->module = g_strdup(filename);
-			if (e->key)
-				g_free(e->key);
-			e->key = g_strdup(key);
-			gtk_widget_show(e->window);
-			gdk_window_raise(gtk_widget_get_parent_window(GTK_WIDGET(e->window)));
-
-			editor_load_note(e, NULL, NULL);
-
-			return 1;
-			break;
-		case BOOK_EDITOR:
-			if (!e->bookeditor)
-				break;
-			if (editor_is_dirty(e))
-				_save_book(e);
-			if (e->module)
-				g_free(e->module);
-			e->module = g_strdup(filename);
-			if (e->key)
-				g_free(e->key);
-			e->key = g_strdup(key);
-			gtk_widget_show(e->window);
-			gdk_window_raise(gtk_widget_get_parent_window(GTK_WIDGET(e->window)));
-			main_load_book_tree_in_editor(GTK_TREE_VIEW(e->treeview),
-						      e->module);
-			editor_load_book(e);
-
-			return 1;
-			break;
-		}
-		tmp = g_list_next(tmp);
-	}
-	XI_message(("filename %s, key %s",
-		    (filename ? filename : "-null-"),
-		    (key ? key : "-null-")));
-	return _create_new(filename, key, editor_type);
+	return 1;
 }
 
 void editor_maybe_save_all(void)
 {
-	GList *tmp, *tmp2;
-
-	tmp = g_list_first(editors_all);
-	while (tmp != NULL) {
-		/* 2ndary list chaser:
-		   elements will be removed by the saver. */
-		tmp2 = g_list_next(tmp);
-
-		delete_event(NULL, NULL, (EDITOR *)tmp->data);
-		tmp = tmp2;
-	}
 }
 
 #endif /* USE_WEBKIT_EDITOR */
