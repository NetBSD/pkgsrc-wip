# $NetBSD: options.mk$

PKG_OPTIONS_VAR=	PKG_OPTIONS.openfortivpn
PKG_SUPPORTED_OPTIONS+=	openfortivpn-obsolete
PKG_SUPPORTED_OPTIONS+=	openfortivpn-rt-dst

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenfortivpn-obsolete)
CONFIGURE_ARGS+=	--enable-obsolete
.endif

.if !empty(PKG_OPTIONS:Mopenfortivpn-rt-dst) && ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-rt_dst
.endif
