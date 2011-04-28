# $NetBSD: options.mk,v 1.2 2011/04/28 03:09:01 rxg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.chromium
.if ${MACHINE_ARCH} != "arm"
PKG_SUPPORTED_OPTIONS=	cups
.endif
PKG_SUPPORTED_OPTIONS+=	codecs debug gnome-keyring
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
GYP_DEFINES+=	use_cups=1
.  include "../../print/cups/buildlink3.mk"
.else
GYP_DEFINES+=	use_cups=0
.endif

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

.if !empty(PKG_OPTIONS:Mgnome-keyring)
GYP_DEFINES+=	linux_link_gnome_keyring=1
GYP_DEFINES+=	use_gnome_keyring=1
.  include "../../security/libgnome-keyring/buildlink3.mk"
.else
GYP_DEFINES+=	use_gnome_keyring=0
.endif
