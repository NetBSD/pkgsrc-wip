# $NetBSD: options.mk,v 1.2 2005/07/20 17:22:15 udontknow Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openct
PKG_SUPPORTED_OPTIONS=	pcsc-lite usb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../wip/pcsc-lite/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-pcsclite=no
.endif

.if !empty(PKG_OPTIONS:Musb)
.include "../../devel/libusb/buildlink3.mk"
.endif
