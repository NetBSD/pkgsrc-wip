# $NetBSD$

BUILDLINK_TREE+=	libimobiledevice

.if !defined(LIBIMOBILEDEVICE_BUILDLINK3_MK)
LIBIMOBILEDEVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libimobiledevice+=	libimobiledevice>=1.2.0
BUILDLINK_ABI_DEPENDS.libimobiledevice+=	libimobiledevice>=1.2.0
BUILDLINK_PKGSRCDIR.libimobiledevice?=		../../wip/libimobiledevice

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../wip/libtatsu/buildlink3.mk"
.include "../../wip/libusbmuxd/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # LIBIMOBILEDEVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimobiledevice
