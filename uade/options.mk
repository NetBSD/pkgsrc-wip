# $NetBSD: options.mk,v 1.1 2012/12/09 15:28:45 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uade
PKG_SUPPORTED_OPTIONS=	audacious xmms
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maudacious)
DEPENDS+=		audacious-plugins-[0-9]*:../../audio/audacious-plugins
.else
CONFIGURE_ARGS+=	--without-audacious
.endif

.if !empty(PKG_OPTIONS:Mxmms)
.include "../../audio/xmms/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xmms
.endif
