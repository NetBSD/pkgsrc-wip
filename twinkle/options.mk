# $NetBSD: options.mk,v 1.1 2007/10/06 22:44:06 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.twinkle
PKG_SUPPORTED_OPTIONS=	ilbc kde speex zrtp
.include "../../mk/bsd.options.mk"

###
### Support for iLBC
###
.if !empty(PKG_OPTIONS:Milbc)
CONFIGURE_ARGS+=	"--with-ilbc"
.include                "../../wip/ilbc-rfc3951/buildlink3.mk"
.else
CONFIGURE_ARGS+=	"--without-ilbc"
.endif

###
### Support for KDE
###
.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ARGS+=	"--with-kde"
.include		"../../meta-pkgs/kde3/kde3.mk"
.else
CONFIGURE_ARGS+=	"--without-kde"
.endif

###
### Support for Speex
###
.if !empty(PKG_OPTIONS:Mspeex)
CONFIGURE_ARGS+=	"--with-speex"
.else
CONFIGURE_ARGS+=	"--without-speex"
.endif

###
### Support for ZRTP
###
.if !empty(PKG_OPTIONS:Mzrtp)
CONFIGURE_ARGS+=	"--with-zrtp"
.else
CONFIGURE_ARGS+=	"--without-zrtp"
.endif
