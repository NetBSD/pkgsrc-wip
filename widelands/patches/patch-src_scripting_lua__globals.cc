$NetBSD$

Use C linking for Lua-called functions.

--- src/scripting/lua_globals.cc.orig	2024-03-28 10:12:05.000000000 +0000
+++ src/scripting/lua_globals.cc
@@ -73,7 +73,7 @@ files name.
 */
 // The 'b' in bformat used to stand for "boost", which we no longer use, but
 // renaming the Lua function would break backwards compatibility.
-static int L_string_bformat(lua_State* L) {
+extern "C" int L_string_bformat(lua_State* L) {
 	try {
 		format_impl::ArgsVector fmt_args;
 		format_impl::ArgsPair arg;
@@ -151,7 +151,7 @@ static std::map<const lua_State*, std::v
       :type domain: :class:`string`
       :returns: :const:`nil`
 */
-static int L_push_textdomain(lua_State* L) {
+extern "C" int L_push_textdomain(lua_State* L) {
 	textdomains[L].push_back(
 	   std::make_pair(luaL_checkstring(L, 1), lua_gettop(L) > 1 && luaL_checkboolean(L, 2)));
 	return 0;
@@ -165,7 +165,7 @@ static int L_push_textdomain(lua_State* 
 
       :returns: :const:`nil`
 */
-static int L_pop_textdomain(lua_State* L) {
+extern "C" int L_pop_textdomain(lua_State* L) {
 	textdomains.at(L).pop_back();
 	return 0;
 }
@@ -234,7 +234,7 @@ void write_textdomain_stack(FileWrite& f
 */
 CLANG_DIAG_RESERVED_IDENTIFIER_OFF
 // NOLINTNEXTLINE(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)
-static int L__(lua_State* L) {
+extern "C" int L__(lua_State* L) {
 	CLANG_DIAG_RESERVED_IDENTIFIER_ON
 	if (const TextdomainInfo* td = current_textdomain(L)) {
 		if (td->second) {
@@ -266,7 +266,7 @@ static int L__(lua_State* L) {
 
    :returns: The translated string.
 */
-static int L_ngettext(lua_State* L) {
+extern "C" int L_ngettext(lua_State* L) {
 	//  S: msgid msgid_plural n
 	const char* msgid = luaL_checkstring(L, 1);
 	const char* msgid_plural = luaL_checkstring(L, 2);
@@ -303,7 +303,7 @@ static int L_ngettext(lua_State* L) {
 
    :returns: The translated string.
 */
-static int L_pgettext(lua_State* L) {
+extern "C" int L_pgettext(lua_State* L) {
 	//  S: msgctxt msgid
 	const char* msgctxt = luaL_checkstring(L, 1);
 	const char* msgid = luaL_checkstring(L, 2);
@@ -340,7 +340,7 @@ static int L_pgettext(lua_State* L) {
 
    :returns: The translated string.
 */
-static int L_npgettext(lua_State* L) {
+extern "C" int L_npgettext(lua_State* L) {
 	//  S: msgctxt msgid
 	const char* msgctxt = luaL_checkstring(L, 1);
 	const char* msgid = luaL_checkstring(L, 2);
@@ -375,7 +375,7 @@ static int L_npgettext(lua_State* L) {
       :arg script: The filename relative to the root of the data directory.
       :returns: :const:`nil`
 */
-static int L_include(lua_State* L) {
+extern "C" int L_include(lua_State* L) {
 	const std::string script = luaL_checkstring(L, -1);
 	// remove our arguments so that the executed script gets a clear stack
 	lua_pop(L, 1);
@@ -398,7 +398,7 @@ static int L_include(lua_State* L) {
    Returns an integer value representing the number of milliseconds since the SDL library
    initialized.
 */
-static int L_ticks(lua_State* L) {
+extern "C" int L_ticks(lua_State* L) {
 	lua_pushinteger(L, SDL_GetTicks());
 	return 1;
 }
@@ -411,14 +411,14 @@ static int L_ticks(lua_State* L) {
    "1.2~git26354 (4ba897c@master)" (development for 1.2) or
    "build-16[debug]" (old, before version 1.0).
 */
-static int L_get_build_id(lua_State* L) {
+extern "C" int L_get_build_id(lua_State* L) {
 	lua_pushstring(L, build_id());
 	return 1;
 }
 
 // set_textdomain() was deprecated before v1.0, removed in v1.2
 // TODO(tothxa): Remove if the position in kPersistentGlobals can be filled with a new function?
-static int L_set_textdomain(lua_State*) {
+extern "C" int L_set_textdomain(lua_State*) {
 	throw LuaError("set_textdomain() is no longer supported");
 }
 
