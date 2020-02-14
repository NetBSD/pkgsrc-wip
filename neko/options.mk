# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.neko

PKG_SUPPORTED_OPTIONS=	# defined
PKG_SUPPORTED_OPTIONS+=	apache
PKG_SUPPORTED_OPTIONS+=	mysql
PKG_SUPPORTED_OPTIONS+=	nekoml
PKG_SUPPORTED_OPTIONS+=	regexp
PKG_SUPPORTED_OPTIONS+=	sqlite
PKG_SUPPORTED_OPTIONS+=	ssl
PKG_SUPPORTED_OPTIONS+=	ui

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	apache
PLIST_VARS+=	mysql
PLIST_VARS+=	nekoml
PLIST_VARS+=	regexp
PLIST_VARS+=	sqlite
PLIST_VARS+=	ssl
PLIST_VARS+=	ui

.if !empty(PKG_OPTIONS:Mapache)
CMAKE_ARGS+=	-DWITH_APACHE:BOOL=ON
.include "../../www/apache24/buildlink3.mk"
PLIST.apache=	yes
.else
CMAKE_ARGS+=	-DWITH_APACHE:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CMAKE_ARGS+=	-DWITH_MYSQL:BOOL=ON
.include "../../databases/mysql57-client/buildlink3.mk"
PLIST.mysql=	yes
.else
CMAKE_ARGS+=	-DWITH_MYSQL:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mnekoml)
CMAKE_ARGS+=	-DWITH_NEKOML:BOOL=ON
PLIST.nekoml=	yes
.else
CMAKE_ARGS+=	-DWITH_NEKOML:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mregexp)
CMAKE_ARGS+=	-DWITH_REGEXP:BOOL=ON
.include "../../devel/pcre/buildlink3.mk"
PLIST.regexp=	yes
.else
CMAKE_ARGS+=	-DWITH_REGEXP:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CMAKE_ARGS+=	-DWITH_SQLITE:BOOL=ON
.include "../../databases/sqlite3/buildlink3.mk"
PLIST.sqlite=	yes
.else
CMAKE_ARGS+=	-DWITH_SQLITE:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mssl)
CMAKE_ARGS+=	-DWITH_SSL:BOOL=ON
.include "../../security/mbedtls/buildlink3.mk"
PLIST.ssl=	yes
.else
CMAKE_ARGS+=	-DWITH_SSL:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mui)
CMAKE_ARGS+=	-DWITH_UI:BOOL=ON
.include "../../x11/gtk2/buildlink3.mk"
PLIST.ui=	yes
.else
CMAKE_ARGS+=	-DWITH_UI:BOOL=OFF
.endif
