# $NetBSD: options.mk,v 1.1 2009/08/26 18:51:38 gduzan Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kmymoney2
PKG_SUPPORTED_OPTIONS=	libofx #sqlite3
PKG_SUGGESTED_OPTIONS=	libofx #sqlite3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		libofx #sqlite3

.if !empty(PKG_OPTIONS:Mlibofx)
.include "../../finance/libofx/buildlink3.mk"
PLIST.libofx=		yes
.endif

#.if !empty(PKG_OPTIONS:Msqlite3)
#.include "../../databases/sqlite3/buildlink3.mk"
#PLIST.sqlite3=		yes
#.endif
