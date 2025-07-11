# $NetBSD$

BUILDLINK_TREE+=	libudev-bsd

.if !defined(LIBUDEV_BSD_BUILDLINK3_MK)
LIBUDEV_BSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libudev-bsd+=	libudev-bsd>=0.6.0.2
BUILDLINK_ABI_DEPENDS.libudev-bsd+=	libudev-bsd>=0.6.0.2
BUILDLINK_PKGSRCDIR.libudev-bsd?=	../../wip/libudev-bsd

.endif # LIBUDEV_BSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libudev-bsd
