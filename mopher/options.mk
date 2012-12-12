# $NetBSD: options.mk,v 1.2 2012/12/12 15:30:30 lexort Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mopher
PKG_SUPPORTED_OPTIONS=	bdb mysql spf
PKG_SUGGESTED_OPTIONS=	bdb spf

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# The use of db method is selected by config file; multiple methods
# can be compiled in.  There is a builtin (non-option) memdb, which is
# not persistent across processes, so no database option is a plausible
# configuration.

# bdb
.if !empty(PKG_OPTIONS:Mbdb)
CONFIGURE_ARGS+=	--with-bdb
PLIST.bdb=		yes
BDB_ACCEPTED=		db4
BUILDLINK_TRANSFORM+=	l:db:db4
.include "../../mk/bdb.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

# mysql
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
PLIST.mysql=		yes
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

# spf
.if !empty(PKG_OPTIONS:Mspf)
CONFIGURE_ARGS+=	--with-spf2
PLIST.spf=		yes
.include "../../mail/libspf2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-spf2
.endif
