# $NetBSD: options.mk,v 1.2 2008/12/30 15:05:21 pebog Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dcc
PKG_SUPPORTED_OPTIONS=	dccd dccifd dccm
PKG_SUGGESTED_OPTIONS=	dccd dccifd

.include "../../mk/bsd.options.mk"

PLIST_VARS=		dccd dccifd dccm dns-helper

###
### Don't build dccd, the DCC server.
###
.if empty(PKG_OPTIONS:Mdccd)
CONFIGURE_ARGS+=	--disable-server
.else
CONF_FILES+=		${DCC_EGDIR}/flod ${DCC_HOME}/flod \
			${DCC_EGDIR}/grey_flod ${DCC_HOME}/grey_flod \
			${DCC_EGDIR}/whitelist ${DCC_HOME}/whitelist \
			${DCC_EGDIR}/grey_whitelist ${DCC_HOME}/grey_whitelist
PLIST.dccd=		yes
RCD_SCRIPTS+=		dccd
.endif

###
### Don't build dccifd, the DCC program interface.
###
.if empty(PKG_OPTIONS:Mdccifd)
CONFIGURE_ARGS+=	--disable-dccifd
.else
PLIST.dccifd=		yes
PLIST.dns-helper=	yes
RCD_SCRIPTS+=		dccifd
.endif

###
### Don't build dccm, the DCC milter.
###
.if empty(PKG_OPTIONS:Mdccm)
CONFIGURE_ARGS+=	--disable-dccm
.else
.include "../../mail/libmilter/buildlink3.mk"
PLIST.dccm=		yes
PLIST.dns-helper=	yes
RCD_SCRIPTS+=		dccm
.endif
