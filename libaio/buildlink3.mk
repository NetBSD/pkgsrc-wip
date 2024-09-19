# $NetBSD$

BUILDLINK_TREE+=	libaio

.if !defined(LIBAIO_BUILDLINK3_MK)
LIBAIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaio+=	libaio>=0.3.112
BUILDLINK_PKGSRCDIR.libaio?=	../../wip/libaio

.endif

BUILDLINK_TREE+=	-libaio
