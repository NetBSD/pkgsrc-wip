# $NetBSD: options.mk,v 1.0 2024/05/13 15:00:00 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnatcoll-db
PKG_SUPPORTED_OPTIONS=		gnatcoll-db2ada gnatcoll-postgres2ada gnatcoll-sqlite2ada gnatcoll-all2ada \
				gnatcoll-gnatinspect gnatcoll-postgres gnatcoll-sql gnatcoll-sqlite gnatcoll-xref
PKG_OPTIONS_OPTIONAL_GROUPS=	shared-libs
PKG_OPTIONS_GROUP.shared-libs=	enable-shared-libs disable-shared-libs
PKG_SUGGESTED_OPTIONS=		gnatcoll-db2ada gnatcoll-postgres2ada gnatcoll-sqlite2ada gnatcoll-all2ada \
				gnatcoll-gnatinspect gnatcoll-postgres gnatcoll-sql gnatcoll-sqlite gnatcoll-xref

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menable-shared-libs)
CONFIGURE_FLAGS+=			ENABLE_SHARED=yes
USE_GCC_RUNTIME=			yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.endif
.if !empty(PKG_OPTIONS:Mdisable-shared-libs)
CONFIGURE_FLAGS+=			ENABLE_SHARED=no
.endif
.if empty(PKG_OPTIONS:Menable-shared-libs) && empty(PKG_OPTIONS:Mdisable-shared-libs)
USE_GCC_RUNTIME=			yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.endif

# Build order is important
.if !empty(PKG_OPTIONS:Mgnatcoll-sql)
PKG_BUILD_DIRS+=		sql
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-sqlite)
#.  include "../../databases/sqlite3/buildlink3.mk"
PKG_BUILD_DIRS+=		sqlite
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres)
PKG_BUILD_DIRS+=		postgres
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-xref)
PKG_BUILD_DIRS+=		xref
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-gnatinspect)
PKG_BUILD_DIRS+=		gnatinspect
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres) || !empty(PKG_OPTIONS:Mgnatcoll-xref) || \
    !empty(PKG_OPTIONS:Mgnatcoll-gnatinspect)
.  include "../../wip/gnatcoll-bindings/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-db2ada) || !empty(PKG_OPTIONS:Mgnatcoll-postgres2ada) || \
    !empty(PKG_OPTIONS:Mgnatcoll-sqlite2ada) || !empty(PKG_OPTIONS:Mgnatcoll-all2ada)
PKG_BUILD_DIRS+=		gnatcoll_db2ada
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres) || \
    !empty(PKG_OPTIONS:Mgnatcoll-postgres2ada) || !empty(PKG_OPTIONS:Mgnatcoll-all2ada)
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-db2ada)
DB_BACKENDS+=			db
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres2ada)
DB_BACKENDS+=			postgres
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-sqlite2ada)
DB_BACKENDS+=			sqlite
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-all2ada)
DB_BACKENDS+=			all
.endif
