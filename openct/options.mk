# $NetBSD: options.mk,v 1.5 2008/05/06 13:21:23 htepper Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openct
PKG_SUPPORTED_OPTIONS=	pcsc-lite usb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pcsclite
PLIST_SRC+=		${PKGDIR}/PLIST.pcsc-lite
.else
CONFIGURE_ARGS+=	--with-pcsclite=no
.endif

.if !empty(PKG_OPTIONS:Musb)
.include "../../devel/libusb/buildlink3.mk"
.endif
