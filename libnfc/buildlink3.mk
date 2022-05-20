# $NetBSD$

BUILDLINK_TREE+=	libnfc

.if !defined(LIBNFC_BUILDLINK3_MK)
LIBNFC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnfc+=	libnfc>=1.7.1
BUILDLINK_ABI_DEPENDS.libnfc+=	libnfc>=1.8.0
BUILDLINK_PKGSRCDIR.libnfc?=	../../wip/libnfc

pkgbase :=	libnfc
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libnfc:Mpcsc}
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Mpcsc)
.include "../../security/pcsc-lite/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libnfc:Macr122pcsc}
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Macr122pcsc)
.include "../../security/pcsc-lite/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libnfc:Macr122usb}
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Macr122usb)
.include "../../mk/libusb.buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libnfc:Mpn53xusb}
#.if !empty(PKG_BUILD_OPTIONS.libnfc:Mpn53xusb)
.include "../../mk/libusb.buildlink3.mk"
.endif

.include "../../devel/readline/buildlink3.mk"
.endif # LIBNFC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnfc
