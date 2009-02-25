# $NetBSD: options.mk,v 1.3 2009/02/25 12:31:54 pebog Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dcc
PKG_SUPPORTED_OPTIONS=	dccm
PKG_SUGGESTED_OPTIONS=	

.include "../../mk/bsd.options.mk"

PLIST_VARS=		dccm

###
### Enable dccm, the DCC milter interface.
###
.if empty(PKG_OPTIONS:Mdccm)
CONFIGURE_ARGS+=	--disable-dccm
.else
RCD_SCRIPTS+=		dccm
PLIST.dccm=		yes
dccm-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dccm/dccm ${DESTDIR}${PREFIX}/libexec/
.include "../../mail/libmilter/buildlink3.mk"
.endif
