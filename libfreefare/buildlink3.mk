# $NetBSD$

BUILDLINK_TREE+=	libfreefare

.if !defined(LIBFREEFARE_BUILDLINK3_MK)
LIBFREEFARE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfreefare+=	libfreefare>=0.4.0
BUILDLINK_ABI_DEPENDS.libfreefare+=	libfreefare>=0.4.0
BUILDLINK_PKGSRCDIR.libfreefare?=	../../wip/libfreefare

#pkgbase :=	libnfc
#.include "../../mk/pkg-build-options.mk"
#
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Mpcsc)
#.include "../../security/pcsc-lite/buildlink3.mk"
#.endif
#
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Macr122_pcsc)
#.include "../../security/pcsc-lite/buildlink3.mk"
#.endif
#
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Macr122_usb)
#.include "../../mk/libusb.buildlink3.mk"
#.endif
#
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Mpn53x_usb)
#.include "../../mk/libusb.buildlink3.mk"
#.endif

#.include "../../devel/readline/buildlink3.mk"
.endif # LIBFREEFARE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfreefare
