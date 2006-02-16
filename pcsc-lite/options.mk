# $NetBSD: options.mk,v 1.2 2006/02/16 20:30:18 ghen Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.pcsc-lite
PKG_SUPPORTED_OPTIONS=	extendedapdu usb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mextendedapdu)
CONFIGURE_ARGS+=	--enable-extendedapdu
.else
CONFIGURE_ARGS+=       --enable-extendedapdu=no
.endif

.if !empty(PKG_OPTIONS:Musb)
CONFIGURE_ARGS+=	--enable-libusb
.include "../../devel/libusb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif
