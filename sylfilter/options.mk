# $NetBSD: options.mk,v 1.1 2012/10/20 20:17:36 ishit Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sylfilter
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	gdbm qdbm sqlite
PKG_SUGGESTED_OPTIONS=		sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgdbm)
CONFIGURE_ARGS+=		--disable-sqlite
CONFIGURE_ARGS+=		--enable-gdbm
.include "../../databases/gdbm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqdbm)
CONFIGURE_ARGS+=		--disable-sqlite
CONFIGURE_ARGS+=		--enable-qdbm
.include "../../databases/qdbm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=		--enable-sqlite
.include "../../databases/sqlite3/buildlink3.mk"
.endif
