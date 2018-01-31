# $NetBSD: options.mk,v 1.2 2013/09/19 05:07:11 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.akonadi

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql sqlite

PKG_SUGGESTED_OPTIONS=		sqlite

.include "../../mk/bsd.options.mk"

###
### Use sqlite backend
###
PLIST_VARS+=	sqlite
.if !empty(PKG_OPTIONS:Msqlite)
.	include "../../databases/sqlite3/buildlink3.mk"
CMAKE_ARGS+=	-DAKONADI_BUILD_QSQLITE:BOOL=ON
CMAKE_ARGS+=	-DDATABASE_BACKEND=SQLITE
PLIST.sqlite=	yes
.endif
