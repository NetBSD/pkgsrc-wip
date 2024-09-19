$NetBSD: patch-res_res__xmpp.c,v 1.3 2015/08/09 04:07:13 jnemeth Exp $

--- res/res_xmpp.c.orig	2015-06-04 00:44:42.000000000 +0000
+++ res/res_xmpp.c
@@ -511,11 +511,14 @@ static void *xmpp_config_find(struct ao2
 	return ao2_find(tmp_container, category, OBJ_KEY);
 }
 
+RAII_DECL(struct xmpp_config *, cfg, ao2_cleanup);
+RAII_DECL(struct ast_xmpp_client_config *, clientcfg, ao2_cleanup);
+
 /*! \brief Look up existing client or create a new one */
 static void *xmpp_client_find_or_create(const char *category)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 
 	if (!cfg || !cfg->clients || !(clientcfg = xmpp_config_find(cfg->clients, category))) {
 		return xmpp_client_alloc(category);
@@ -601,11 +604,13 @@ error:
 	return NULL;
 }
 
+RAII_DECL(struct ast_xmpp_client_config *, oldclientcfg, ao2_cleanup);
+
 static int xmpp_config_prelink(void *newitem)
 {
 	struct ast_xmpp_client_config *clientcfg = newitem;
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, oldclientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, oldclientcfg, NULL);
 
 	if (ast_strlen_zero(clientcfg->user)) {
 		ast_log(LOG_ERROR, "No user specified on client '%s'\n", clientcfg->name);
@@ -641,7 +646,7 @@ static int xmpp_config_prelink(void *new
 
 static void xmpp_config_post_apply(void)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
 
 	ao2_callback(cfg->clients, OBJ_NODATA | OBJ_MULTIPLE, xmpp_client_config_post_apply, NULL);
 }
@@ -727,8 +732,8 @@ static int xmpp_is_secure(struct ast_xmp
 
 struct ast_xmpp_client *ast_xmpp_client_find(const char *name)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 
 	if (!cfg || !cfg->clients || !(clientcfg = xmpp_config_find(cfg->clients, name))) {
 		return NULL;
@@ -756,8 +761,8 @@ void ast_xmpp_client_unlock(struct ast_x
 /*! \brief Internal function used to send a message to a user or chatroom */
 static int xmpp_client_send_message(struct ast_xmpp_client *client, int group, const char *nick, const char *address, const char *message)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	int res = 0;
 	char from[XMPP_MAX_JIDLEN];
 	iks *message_packet;
@@ -820,8 +825,8 @@ done:
 
 static int xmpp_client_set_group_presence(struct ast_xmpp_client *client, const char *room, int level, const char *nick)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	int res = 0;
 	iks *presence = NULL, *x = NULL;
 	char from[XMPP_MAX_JIDLEN], roomid[XMPP_MAX_JIDLEN];
@@ -891,8 +896,8 @@ void ast_xmpp_increment_mid(char *mid)
  */
 static iks* xmpp_pubsub_iq_create(struct ast_xmpp_client *client, const char *type)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	iks *request;
 
 	if (!cfg || !cfg->clients || !(clientcfg = xmpp_config_find(cfg->clients, client->name)) ||
@@ -924,7 +929,7 @@ static iks* xmpp_pubsub_iq_create(struct
 static iks* xmpp_pubsub_build_publish_skeleton(struct ast_xmpp_client *client, const char *node,
 					       const char *event_type, unsigned int cachable)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
 	iks *request, *pubsub, *publish, *item;
 
 	if (!cfg || !cfg->global || !(request = xmpp_pubsub_iq_create(client, "set"))) {
@@ -1150,7 +1155,7 @@ static void xmpp_pubsub_publish_mwi(stru
 static void xmpp_pubsub_publish_device_state(struct ast_xmpp_client *client, const char *device,
 					     const char *device_state, unsigned int cachable)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
 	iks *request, *state;
 	char eid_str[20], cachable_str[2];
 
@@ -1262,7 +1267,7 @@ static void xmpp_pubsub_unsubscribe(stru
  */
 static void xmpp_pubsub_subscribe(struct ast_xmpp_client *client, const char *node)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
 	iks *request = xmpp_pubsub_iq_create(client, "set");
 	iks *pubsub, *subscribe;
 
@@ -1369,7 +1374,7 @@ static int xmpp_pubsub_handle_event(void
 
 static int xmpp_pubsub_handle_error(void *data, ikspak *pak)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
 	char *node_name, *error;
 	int error_num;
 	iks *orig_request, *orig_pubsub = iks_find(pak->x, "pubsub");
@@ -1442,8 +1447,8 @@ static int xmpp_pubsub_handle_error(void
  */
 static void xmpp_init_event_distribution(struct ast_xmpp_client *client)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 
 	if (!cfg || !cfg->clients || !(clientcfg = xmpp_config_find(cfg->clients, client->name))) {
 		return;
@@ -1497,8 +1502,8 @@ static int xmpp_resource_immediate(void 
  */
 static int xmpp_status_exec(struct ast_channel *chan, const char *data)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_buddy *buddy;
 	struct ast_xmpp_resource *resource;
 	char *s = NULL, status[2];
@@ -1576,8 +1581,8 @@ static int xmpp_status_exec(struct ast_c
  */
 static int acf_jabberstatus_read(struct ast_channel *chan, const char *name, char *data, char *buf, size_t buflen)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_buddy *buddy;
 	struct ast_xmpp_resource *resource;
 	int stat = 7;
@@ -1649,8 +1654,8 @@ static struct ast_custom_function jabber
  */
 static int xmpp_join_exec(struct ast_channel *chan, const char *data)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	char *s, nick[XMPP_MAX_RESJIDLEN];
 	AST_DECLARE_APP_ARGS(args,
 			     AST_APP_ARG(sender);
@@ -1708,8 +1713,8 @@ static int xmpp_join_exec(struct ast_cha
  */
 static int xmpp_leave_exec(struct ast_channel *chan, const char *data)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	char *s, nick[XMPP_MAX_RESJIDLEN];
 	AST_DECLARE_APP_ARGS(args,
 			     AST_APP_ARG(sender);
@@ -1769,8 +1774,8 @@ static int xmpp_leave_exec(struct ast_ch
  */
 static int xmpp_send_exec(struct ast_channel *chan, const char *data)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	char *s;
 	AST_DECLARE_APP_ARGS(args,
 			     AST_APP_ARG(sender);
@@ -1810,8 +1815,8 @@ static int xmpp_send_exec(struct ast_cha
  */
 static int xmpp_sendgroup_exec(struct ast_channel *chan, const char *data)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	char *s, nick[XMPP_MAX_RESJIDLEN];
 	AST_DECLARE_APP_ARGS(args,
 			     AST_APP_ARG(sender);
@@ -1863,8 +1868,8 @@ static int xmpp_sendgroup_exec(struct as
  */
 static int acf_jabberreceive_read(struct ast_channel *chan, const char *name, char *data, char *buf, size_t buflen)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	char *parse = NULL;
 	int timeout, jidlen, resourcelen, found = 0;
 	struct timeval start;
@@ -2022,8 +2027,8 @@ static struct ast_custom_function jabber
  */
 static int delete_old_messages(struct ast_xmpp_client *client, char *from)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	int deleted = 0, isold = 0;
 	struct ast_xmpp_message *message = NULL;
 
@@ -2056,8 +2061,8 @@ static int delete_old_messages(struct as
 
 static int xmpp_send_cb(const struct ast_msg *msg, const char *to, const char *from)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	char *sender, *dest;
 	int res;
 
@@ -2181,8 +2186,8 @@ static int xmpp_client_subscribe_user(vo
 /*! \brief Hook function called when roster is received from server */
 static int xmpp_roster_hook(void *data, ikspak *pak)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_client *client = data;
 	iks *item;
 
@@ -2239,8 +2244,8 @@ static int xmpp_roster_hook(void *data, 
 /*! \brief Internal function which changes the presence status of an XMPP client */
 static void xmpp_client_set_presence(struct ast_xmpp_client *client, const char *to, const char *from, int level, const char *desc)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	iks *presence = NULL, *cnode = NULL, *priority = NULL;
 	char priorityS[10];
 
@@ -2367,8 +2372,8 @@ static int xmpp_client_service_discovery
 /*! \brief Hook function called when client finishes authenticating with the server */
 static int xmpp_connect_hook(void *data, ikspak *pak)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_client *client = data;
 	iks *roster;
 
@@ -2405,8 +2410,8 @@ static int xmpp_connect_hook(void *data,
 /*! \brief Logging hook function */
 static void xmpp_log_hook(void *data, const char *xmpp, size_t size, int incoming)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_client *client = data;
 
 	if (!ast_strlen_zero(xmpp)) {
@@ -2748,8 +2753,8 @@ static int xmpp_component_authenticate(s
 /*! \brief Hook function called when component receives a service discovery get message */
 static int xmpp_component_service_discovery_get_hook(void *data, ikspak *pak)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_client *client = data;
 	iks *iq = NULL, *query = NULL, *identity = NULL, *disco = NULL, *reg = NULL, *commands = NULL, *gateway = NULL;
 	iks *version = NULL, *vcard = NULL, *search = NULL, *item = NULL;
@@ -2835,8 +2840,8 @@ done:
 /*! \brief Hook function called when the component is queried about registration */
 static int xmpp_component_register_get_hook(void *data, ikspak *pak)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_client *client = data;
 	iks *iq = NULL, *query = NULL, *error = NULL, *notacceptable = NULL, *instructions = NULL;
 	struct ast_xmpp_buddy *buddy;
@@ -2943,8 +2948,8 @@ done:
 /*! \brief Hook function called when we receive a service discovery items request */
 static int xmpp_component_service_discovery_items_hook(void *data, ikspak *pak)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_client *client = data;
 	iks *iq = NULL, *query = NULL, *item = NULL, *feature = NULL;
 	char *node;
@@ -3327,8 +3332,8 @@ static int xmpp_pak_s10n(struct ast_xmpp
 /*! \brief Action hook for when things occur */
 static int xmpp_action_hook(void *data, int type, iks *node)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	struct ast_xmpp_client *client = data;
 	ikspak *pak;
 	int i;
@@ -3438,8 +3443,8 @@ int ast_xmpp_client_disconnect(struct as
 static int xmpp_client_reconnect(struct ast_xmpp_client *client)
 {
 	struct timeval tv = { .tv_sec = 5, .tv_usec = 0 };
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	int res = IKS_NET_NOCONN;
 
 	if (!cfg || !cfg->clients || !(clientcfg = xmpp_config_find(cfg->clients, client->name))) {
@@ -3614,8 +3619,8 @@ static void *xmpp_client_thread(void *da
 		} else if (res == IKS_NET_TLSFAIL) {
 			ast_log(LOG_ERROR, "JABBER:  Failure in TLS.\n");
 		} else if (!client->timeout && client->state == XMPP_STATE_CONNECTED) {
-			RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-			RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+			RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+			RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 
 			if (cfg && cfg->clients) {
 				clientcfg = xmpp_config_find(cfg->clients, client->name);
@@ -3669,10 +3674,12 @@ static int xmpp_client_config_merge_budd
 	return 1;
 }
 
+RAII_DECL(struct xmpp_config *, gcfg, ao2_cleanup);
+
 static int xmpp_client_config_post_apply(void *obj, void *arg, int flags)
 {
 	struct ast_xmpp_client_config *cfg = obj;
-	RAII_VAR(struct xmpp_config *, gcfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, gcfg, ao2_global_obj_ref(globals));
 
 	/* Merge global options that have not been modified */
 	ast_copy_flags(&cfg->flags, &gcfg->global->general, ~(cfg->mod_flags.flags) & (XMPP_AUTOPRUNE | XMPP_AUTOREGISTER | XMPP_AUTOACCEPT));
@@ -3732,8 +3739,8 @@ static int xmpp_client_config_post_apply
  */
 static int manager_jabber_send(struct mansession *s, const struct message *m)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	const char *id = astman_get_header(m, "ActionID");
 	const char *jabber = astman_get_header(m, "Jabber");
 	const char *screenname = astman_get_header(m, "ScreenName");
@@ -3859,8 +3866,8 @@ static void xmpp_pubsub_request_nodes(st
 static char *xmpp_cli_list_pubsub_nodes(struct ast_cli_entry *e, int cmd, struct
 					ast_cli_args *a)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	const char *name = NULL, *collection = NULL;
 
 	switch (cmd) {
@@ -3945,8 +3952,8 @@ static void xmpp_pubsub_purge_nodes(stru
 static char *xmpp_cli_purge_pubsub_nodes(struct ast_cli_entry *e, int cmd, struct
 					 ast_cli_args *a)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	const char *name;
 
 	switch (cmd) {
@@ -3990,8 +3997,8 @@ static char *xmpp_cli_purge_pubsub_nodes
 static char *xmpp_cli_delete_pubsub_node(struct ast_cli_entry *e, int cmd, struct
 					ast_cli_args *a)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	const char *name;
 
 	switch (cmd) {
@@ -4027,8 +4034,8 @@ static char *xmpp_cli_delete_pubsub_node
  */
 static char *xmpp_cli_create_collection(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	const char *name, *collection_name;
 
 	switch (cmd) {
@@ -4067,8 +4074,8 @@ static char *xmpp_cli_create_collection(
  */
 static char *xmpp_cli_create_leafnode(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
-	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL, ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
+	RAII_VAR(struct ast_xmpp_client_config *, clientcfg, NULL);
 	const char *name, *collection_name, *leaf_name;
 
 	switch (cmd) {
@@ -4143,7 +4150,7 @@ static char *xmpp_do_set_debug(struct as
  */
 static char *xmpp_show_clients(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
 	struct ao2_iterator i;
 	struct ast_xmpp_client_config *clientcfg;
 
@@ -4219,7 +4226,7 @@ static char *xmpp_show_clients(struct as
  */
 static char *xmpp_show_buddies(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
 {
-	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals), ao2_cleanup);
+	RAII_VAR(struct xmpp_config *, cfg, ao2_global_obj_ref(globals));
 	struct ao2_iterator i;
 	struct ast_xmpp_client_config *clientcfg;
 
