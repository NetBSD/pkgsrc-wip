# $NetBSD: options.mk,v 1.1.1.1 2010/01/27 06:50:32 phonohawk Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.aubio
PKG_SUPPORTED_OPTIONS=	jack alsa
PKG_SUGGESTED_OPTIONS=	jack alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.  include "../../audio/jack/buildlink3.mk"
.endif
