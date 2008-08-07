# $NetBSD: options.mk,v 1.6 2008/08/07 18:31:23 htepper Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openct
PKG_SUPPORTED_OPTIONS=	pcsc-lite usb
PKG_SUGGESTED_OPTIONS=	pcsc-lite
PLIST_VARS+=		pcsc-lite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pcsc
PLIST.pcsc-lite=	yes
.else
CONFIGURE_ARGS+=	--disable-pcsc
.endif

.if !empty(PKG_OPTIONS:Musb)
.include "../../devel/libusb/buildlink3.mk"
.endif
