# $NetBSD$

BUILDLINK_TREE+=	libnoise

.if !defined(LIBNOISE_BUILDLINK3_MK)
LIBNOISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnoise+=	libnoise>=1.0.0
BUILDLINK_ABI_DEPENDS.libnoise+=	libnoise>=1.0.0
BUILDLINK_PKGSRCDIR.libnoise?=		../../wip/libnoise
.endif

BUILDLINK_TREE+=	-libnoise
