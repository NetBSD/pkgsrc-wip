$NetBSD$

--- spa/plugins/alsa/alsa-pcm.c.orig	2025-07-29 22:28:04.080110792 +0000
+++ spa/plugins/alsa/alsa-pcm.c
@@ -1033,7 +1033,11 @@ int spa_alsa_init(struct state *state, c
 
 	state->card = ensure_card(state->card_index, state->open_ucm, state->is_split_parent);
 
+#if defined(__NetBSD__)
+	state->log_file = fopen(state, "w");
+#else
 	state->log_file = fopencookie(state, "w", io_funcs);
+#endif
 	if (state->log_file == NULL) {
 		spa_log_error(state->log, "can't create log file");
 		return -errno;
