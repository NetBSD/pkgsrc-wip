# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcem

PKG_SUPPORTED_OPTIONS+=		alsa
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif
