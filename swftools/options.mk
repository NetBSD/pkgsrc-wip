# $NetBSD: options.mk,v 1.1 2010/01/01 23:08:05 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.swftools
PKG_SUPPORTED_OPTIONS=	lame

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	avifile

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+=	--enable-lame
.include "../../audio/lame/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if !empty(PKG_OPTIONS:Mavifile)
PLIST.avifile=		yes
.include "../../wip/avifile-devel/buildlink3.mk"
.endif
