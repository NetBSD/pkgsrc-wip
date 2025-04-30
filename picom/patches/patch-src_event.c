$NetBSD$

../src/event.c: In function 'update_ewmh_active_win':
../src/event.c:203:24: error: parameter name omitted
  203 | update_ewmh_active_win(struct x_connection * /*c*/, struct x_async_request_base *req_base,
      |                        ^~~~~~~~~~~~~~~~~~~~~
../src/event.c: In function 'recheck_focus':
../src/event.c:250:27: error: parameter name omitted
  250 | static void recheck_focus(struct x_connection * /*c*/, struct x_async_request_base *req_base,
      |                           ^~~~~~~~~~~~~~~~~~~~~

--- src/event.c.orig	2025-04-30 22:30:48.223531215 +0000
+++ src/event.c
@@ -200,7 +200,7 @@ struct ev_ewmh_active_win_request {
 /// Does not change anything if we fail to get the attribute or the window
 /// returned could not be found.
 static void
-update_ewmh_active_win(struct x_connection * /*c*/, struct x_async_request_base *req_base,
+update_ewmh_active_win(struct x_connection *foo /*c*/, struct x_async_request_base *req_base,
                        const xcb_raw_generic_event_t *reply_or_error) {
 	auto ps = ((struct ev_ewmh_active_win_request *)req_base)->ps;
 	free(req_base);
@@ -247,7 +247,7 @@ struct ev_recheck_focus_request {
  * @param ps current session
  * @return struct _win of currently focused window, NULL if not found
  */
-static void recheck_focus(struct x_connection * /*c*/, struct x_async_request_base *req_base,
+static void recheck_focus(struct x_connection *foo /*c*/, struct x_async_request_base *req_base,
                           const xcb_raw_generic_event_t *reply_or_error) {
 	auto ps = ((struct ev_ewmh_active_win_request *)req_base)->ps;
 	free(req_base);
