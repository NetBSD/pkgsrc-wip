# $NetBSD: options.mk,v 1.1.1.1 2008/05/24 05:30:58 jkuittinen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.milkytracker
#PKG_SUPPORTED_OPTIONS=	alsa jack jack-devel
PKG_SUPPORTED_OPTIONS=	jack jack-devel
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

#.if !empty(PKG_OPTIONS:Malsa)
#CONFIGURE_ARGS+=	--with-alsa
#.else
CONFIGURE_ARGS+=	--without-alsa
#.endif

.if !empty(PKG_OPTIONS:Mjack) || !empty(PKG_OPTIONS:Mjack-devel)
  CONFIGURE_ARGS+=	--with-jack

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack-devel)
.include "../../audio/jack-devel/buildlink3.mk"
.endif

.else
CONFIGURE_ARGS+=	--without-jack
.endif
