# $NetBSD: options.mk,v 1.3 2013/05/16 10:47:34 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libticables2
PKG_SUPPORTED_OPTIONS=	libusb libusb1 nls
PKG_SUGGESTED_OPTIONS+=	libusb nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibusb)
BUILDLINK_ABI_DEPENDS.libusb+=	libusb>=0.1.12
.include "../../devel/libusb/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibusb1)
.include "../../devel/libusb1/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libusb10
.endif

.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
