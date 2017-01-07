# $NetBSD$

BUILDLINK_TREE+=	libusbmuxd

.if !defined(LIBUSBMUXD_BUILDLINK3_MK)
LIBUSBMUXD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libusbmuxd+=	libusbmuxd>=1.0.10
BUILDLINK_PKGSRCDIR.libusbmuxd?=	../../wip/libusbmuxd

.endif	# LIBUSBMUXD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libusbmuxd
