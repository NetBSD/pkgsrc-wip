# $NetBSD$

BUILDLINK_TREE+=	xwayland

.if !defined(XWAYLAND_BUILDLINK3_MK)
XWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xwayland+=	xwayland>=24.1.8
BUILDLINK_PKGSRCDIR.xwayland?=		../../wip/xwayland

.endif	# XWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-xwayland
