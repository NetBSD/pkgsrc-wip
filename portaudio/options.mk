# $NetBSD: options.mk,v 1.1 2013/05/08 23:57:17 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.portaudio
PKG_SUPPORTED_OPTIONS=	alsa debug jack oss
PKG_SUGGESTED_OPTIONS+=	oss
PLIST_VARS+=		jack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.  if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-alsa
.  else
BROKEN=			The alsa option currently only works for Linux.
.  endif
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug-output
.  if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-mac-debug
.  endif
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jack
PLIST.jack=		yes
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
CONFIGURE_ARGS+=	--with-oss
.else
CONFIGURE_ARGS+=	--without-oss
.endif
