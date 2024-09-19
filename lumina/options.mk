# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS_VAR.lumina
PKG_SUPPORTED_OPTIONS=	noxinput

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnoxinput)
EXTRA=	CONFIG+=NO_XINPUT
.else
EXTRA=
.endif
