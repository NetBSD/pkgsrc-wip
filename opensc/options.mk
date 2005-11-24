# $NetBSD: options.mk,v 1.1.1.1 2005/11/24 03:17:14 udontknow Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensc
PKG_SUPPORTED_OPTIONS=	ccid-pinpad assuan pcsc-lite
PKG_SUGGESTED_OPTIONS=	ccid-pinpad assuan

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mccid-pinpad)
CONFIGURE_ARGS+=	--enable-ccid-pinpad
.else
CONFIGURE_ARGS+=	--enable-ccid-pinpad=no
.endif

.if !empty(PKG_OPTIONS:Massuan)
.include "../../security/libassuan/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../wip/pcsc-lite/buildlink3.mk"
.endif
