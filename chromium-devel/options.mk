# $NetBSD: options.mk,v 1.1 2010/10/21 08:14:32 rxg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.chromium
PKG_SUPPORTED_OPTIONS=	codecs debug
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcodecs)
GYP_DEFINES+=	ffmpeg_branding=Chrome
.else
GYP_DEFINES+=	ffmpeg_branding=Chromium
.endif

.if !empty(PKG_OPTIONS:Mdebug)
BUILDTYPE=	Debug
.else
BUILDTYPE=	Release
.endif
