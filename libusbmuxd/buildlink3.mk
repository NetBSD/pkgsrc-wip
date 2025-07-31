# $NetBSD$

BUILDLINK_TREE+=	libusbmuxd

.if !defined(LIBUSBMUXD_BUILDLINK3_MK)
LIBUSBMUXD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusbmuxd+=	libusbmuxd>=2.1.1
BUILDLINK_PKGSRCDIR.libusbmuxd?=	../../wip/libusbmuxd

.include "../../textproc/libplist/buildlink3.mk"
.include "../../wip/libimobiledevice-glue/buildlink3.mk"
.endif	# LIBUSBMUXD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusbmuxd
