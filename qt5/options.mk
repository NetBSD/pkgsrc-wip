# $NetBSD: options.mk,v 1.2 2013/05/10 12:30:24 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5-libs
PKG_SUPPORTED_OPTIONS=	db2 debug gif glib jpeg mysql opengl openssl pgsql png sqlite sqlite3 tds
PKG_SUGGESTED_OPTIONS+=	${PKG_SUPPORTED_OPTIONS:S/debug//1} # XXX for testing

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb2)
.include "../../databases/db/buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-db2 -plugin-sql-db2
.else
CONFIGURE_ARGS+=	-no-sql-db2
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	-debug -developer-build -qml-debug
CONFIGURE_ARGS+=	-no-separate-debug-info
.else
CONFIGURE_ARGS+=	-release -no-qml-debug -separate-debug-info
.endif

.if !empty(PKG_OPTIONS:Mgif)
.include "../../mk/giflib.buildlink3.mk"
.else
CONFIGURE_ARGS+=	-no-gif
.endif

.if !empty(PKG_OPTIONS:Mglib)
.include "../../devel/glib2/buildlink3.mk"
CONFIGURE_ARGS+=	-glib
.else
CONFIGURE_ARGS+=	-no-glib
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
CONFIGURE_ARGS+=	-system-libjpeg
.else
CONFIGURE_ARGS+=	-no-libjpeg
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-mysql -plugin-sql-mysql
.else
CONFIGURE_ARGS+=	-no-sql-mysql
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
CONFIGURE_ARGS+=	-opengl
.else
CONFIGURE_ARGS+=	-no-opengl
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	-openssl
.else
CONFIGURE_ARGS+=	-no-openssl
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-psql -plugin-sql-psql
.else
CONFIGURE_ARGS+=	-no-sql-psql
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	-system-libpng
.else
CONFIGURE_ARGS+=	-no-png
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite/buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-sqlite2 -plugin-sql-sqlite2
.else
CONFIGURE_ARGS+=	-no-sql-sqlite2
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	-system-sqlite -qt-sql-sqlite -plugin-sql-sqlite
.else
CONFIGURE_ARGS+=	-no-sql-sqlite
.endif

.if !empty(PKG_OPTIONS:Mtds)
.include "../../databases/freetds/buildlink3.mk"
CONFIGURE_ARGS+=	-qt-sql-tds -plugin-sql-tds
.else
CONFIGURE_ARGS+=	-no-sql-tds
.endif
