# $NetBSD: options.mk,v 1.1.1.1 2011/12/13 15:11:47 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupen64plus
PKG_SUPPORTED_OPTIONS=	lirc samplerate
PKG_SUGGESTED_OPTIONS=	samplerate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlirc)
.include "../../wip/lirc/buildlink3.mk"
CFLAGS+=	-DLIRC=1
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.else
#CONFIGURE_ARGS+=	--without-ilbc
.endif
