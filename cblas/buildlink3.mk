# $NetBSD$

BUILDLINK_TREE+=	cblas

.if !defined(CBLAS_BUILDLINK3_MK)
CBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas+=	cblas>=1.0
BUILDLINK_PKGSRCDIR.cblas?=	../../wip/cblas
BUILDLINK_DEPMETHOD.cblas?=	build
.endif

BUILDLINK_TREE+=	-cblas
