# $NetBSD: options.mk,v 1.3 2005/07/23 16:31:21 udontknow Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openct
PKG_SUPPORTED_OPTIONS=	pcsc-lite usb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../wip/pcsc-lite/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.pcsc-lite
.else
CONFIGURE_ARGS+=	--with-pcsclite=no
.endif

.if !empty(PKG_OPTIONS:Musb)
.include "../../devel/libusb/buildlink3.mk"
.endif
