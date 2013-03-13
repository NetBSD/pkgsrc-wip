# $NetBSD: options.mk,v 1.4 2013/03/13 21:33:00 tnn2 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_SUPPORTED_OPTIONS=	sieve
PKG_SUGGESTED_OPTIONS=	sieve

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		sieve

###
### Sieve support
###
.if !empty(PKG_OPTIONS:Msieve)
.include "../../mail/libsieve/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sieve=${BUILDLINK_PREFIX.libsieve}
PLIST.sieve=		yes
FILES_SUBST+=		TIMSIEVED="dbmailtimsieved"
RCD_SCRIPTS+=		dbmailtimsieved
.else
CONFIGURE_ARGS+=	--without-sieve
FILES_SUBST+=		TIMSIEVED=""
.endif
