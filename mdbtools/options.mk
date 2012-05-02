# $NetBSD: options.mk,v 1.1 2012/05/02 08:21:29 noud4 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mdbtools
PKG_SUPPORTED_OPTIONS=		gnome odbc readline

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}	# XXX

.if !empty(PKG_OPTIONS:Mgnome)
PLIST_SRC+=		PLIST PLIST.gmdb		# XXX
.include "../../devel/libgnomeui/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Modbc)
PLIST_SRC+=		PLIST PLIST.odbc		# XXX
CONFIGURE_ARGS+=	--with-unixodbc=${PREFIX}
.include "../../databases/unixodbc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.endif
