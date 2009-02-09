# $NetBSD: options.mk,v 1.3 2009/02/09 21:07:44 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.twinkle
PKG_SUPPORTED_OPTIONS=	ilbc kde speex zrtp
PKG_SUGGESTED_OPTIONS=	kde speex

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Milbc)
.include "../../wip/ilbc-rfc3951/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ilbc
.endif

.if !empty(PKG_OPTIONS:Mkde)
.include "../../x11/kdelibs3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-kde
.endif

.if !empty(PKG_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-speex
.endif

.if !empty(PKG_OPTIONS:Mzrtp)
.include "../../wip/libzrtpcpp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zrtp
.endif
