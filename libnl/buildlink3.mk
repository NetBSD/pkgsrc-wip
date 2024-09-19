# $NetBSD$

BUILDLINK_TREE+=	libnl

.if !defined(LIBNL_BUILDLINK3_MK)
LIBNL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnl+=	libnl>=3.2.25
BUILDLINK_PKGSRCDIR.libnl?=	../../wip/libnl
.endif

BUILDLINK_TREE+=	-libnl
