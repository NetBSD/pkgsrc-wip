# $NetBSD$

BUILDLINK_TREE+=	libwacom

.if !defined(LIBWACOM_BUILDLINK3_MK)
LIBWACOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwacom+=	libwacom>=2.14.0
BUILDLINK_PKGSRCDIR.libwacom?=		../../wip/libwacom

#.include "../../wip/libgudev/buildlink3.mk"
.include "../../wip/libevdev/buildlink3.mk"
.endif	# LIBWACOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwacom
