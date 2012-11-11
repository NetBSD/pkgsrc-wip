# $NetBSD: options.mk,v 1.4 2012/11/11 12:23:39 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.twinkle
PKG_SUPPORTED_OPTIONS=	alsa ilbc kde speex zrtp
PKG_SUGGESTED_OPTIONS=	ilbc speex zrtp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

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
