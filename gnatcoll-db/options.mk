# $NetBSD: options.mk,v 1.0 2024/05/13 15:00:00 dkazankov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnatcoll-db
PKG_SUPPORTED_OPTIONS=	gnatcoll_db2ada gnatcoll_postgres2ada gnatcoll_sqlite2ada gnatcoll_all2ada
PKG_SUPPORTED_OPTIONS+=	gnatinspect postgres sql sqlite xref
PKG_SUGGESTED_OPTIONS=	gnatcoll_db2ada gnatcoll_postgres2ada gnatcoll_sqlite2ada gnatcoll_all2ada
PKG_SUGGESTED_OPTIONS+=	gnatinspect postgres sql sqlite xref

.include "../../mk/bsd.fast.prefs.mk"

.include "../../mk/bsd.options.mk"

CONFIGURE_DIRS=
BUILD_DIRS=
INSTALL_DIRS=

# Build order is important

.if !empty(PKG_OPTIONS:Msql)
CONFIGURE_DIRS+=	sql
BUILD_DIRS+=		sql
INSTALL_DIRS+=		sql
.endif

.if !empty(PKG_OPTIONS:Msqlite)
#.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_DIRS+=	sqlite
BUILD_DIRS+=		sqlite
INSTALL_DIRS+=		sqlite
.endif

.if !empty(PKG_OPTIONS:Mpostgres)
.  include "../../wip/gnatcoll-bindings/buildlink3.mk"
CONFIGURE_DIRS+=	postgres
BUILD_DIRS+=		postgres
INSTALL_DIRS+=		postgres
.endif

.if !empty(PKG_OPTIONS:Mxref)
.  include "../../wip/gnatcoll-bindings/buildlink3.mk"
CONFIGURE_DIRS+=	xref
BUILD_DIRS+=		xref
INSTALL_DIRS+=		xref
.endif

.if !empty(PKG_OPTIONS:Mgnatinspect)
.  include "../../wip/gnatcoll-bindings/buildlink3.mk"
CONFIGURE_DIRS+=	gnatinspect
BUILD_DIRS+=		gnatinspect
INSTALL_DIRS+=		gnatinspect
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll_db2ada) || !empty(PKG_OPTIONS:Mgnatcoll_postgres2ada) || \
    !empty(PKG_OPTIONS:Mgnatcoll_sqlite2ada) || !empty(PKG_OPTIONS:Mgnatcoll_all2ada)
CONFIGURE_DIRS+=	gnatcoll_db2ada
BUILD_DIRS+=		gnatcoll_db2ada
INSTALL_DIRS+=		gnatcoll_db2ada
.endif

.if !empty(PKG_OPTIONS:Mpostgres) || \
    !empty(PKG_OPTIONS:Mgnatcoll_postgres2ada) || !empty(PKG_OPTIONS:Mgnatcoll_all2ada)
.  include "../../mk/pgsql.buildlink3.mk"
.endif
