# $NetBSD: options.mk,v 1.1.1.1 2010/03/12 22:17:30 christtrekker Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tuxguitar
PKG_SUPPORTED_OPTIONS+=	audiounit coreaudio alsa ascii carbon cocoa
PKG_SUPPORTED_OPTIONS+=	community compat converter fluidsynth ftp gervill
PKG_SUPPORTED_OPTIONS+=	gtp jack jsa jws lilypond midi musicxml oss
PKG_SUPPORTED_OPTIONS+=	pdf ptb tef tray tuner winmm
PKG_SUGGESTED_OPTIONS+=	audiounit coreaudio alsa ascii
.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=	carbon cocoa
.endif
PKG_SUGGESTED_OPTIONS+=	community compat converter fluidsynth ftp gervill
PKG_SUGGESTED_OPTIONS+=	gtp jack jsa jws lilypond midi musicxml oss
PKG_SUGGESTED_OPTIONS+=	pdf ptb tef tray tuner winmm

.include "../../mk/bsd.options.mk"
