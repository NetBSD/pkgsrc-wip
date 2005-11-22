# $NetBSD: options.mk,v 1.6 2005/11/22 06:00:25 dhowland Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freevo
PKG_SUPPORTED_OPTIONS=		mencoder xine lame flac oggenc xmltv xmame
PKG_OPTIONS_OPTIONAL_GROUPS=	snes
PKG_OPTIONS_GROUP.snes=		snes9x zsnes
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmencoder)
DEPENDS+=		mencoder>=1.0rc3:../../multimedia/mencoder
.endif

.if !empty(PKG_OPTIONS:Mxine)
DEPENDS+=		xine-ui>=0.99.2:../../multimedia/xine-ui
.endif

.if !empty(PKG_OPTIONS:Mlame)
DEPENDS+=		lame>=3.96.1:../../audio/lame
.endif

.if !empty(PKG_OPTIONS:Mflac)
DEPENDS+=		flac>=1.1.2:../../audio/flac
.endif

.if !empty(PKG_OPTIONS:Moggenc)
DEPENDS+=		vorbis-tools>=1.1.1:../../audio/vorbis-tools
.endif

.if !empty(PKG_OPTIONS:Mxmltv)
DEPENDS+=		p5-xmltv>=0.5.40:../../multimedia/p5-xmltv
.endif

.if !empty(PKG_OPTIONS:Mxmame)
DEPENDS+=		xmame>=0.101:../../emulators/xmame
.endif

.if !empty(PKG_OPTIONS:Msnes9x)
DEPENDS+=		snes9x>=1.39:../../emulators/snes9x
.elif !empty(PKG_OPTIONS:Mzsnes)
DEPENDS+=		zsnes>=1.42:../../emulators/zsnes
.endif
