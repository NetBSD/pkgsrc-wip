# $NetBSD: options.mk,v 1.2 2007/10/07 08:38:24 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.twinkle
PKG_SUPPORTED_OPTIONS=	ilbc kde speex # zrtp
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

#.if !empty(PKG_OPTIONS:Mzrtp)
#BROKEN=		libzrtpcpp not packaged yet.
#.else
#CONFIGURE_ARGS+=	--without-zrtp
#.endif
