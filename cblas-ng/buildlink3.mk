# $NetBSD$

BUILDLINK_TREE+=	cblas

.if !defined(CBLAS_BUILDLINK3_MK)
CBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas+=	cblas-ng>=3.8.0
BUILDLINK_PKGSRCDIR.cblas?=	../../wip/cblas-ng
.endif

BUILDLINK_TREE+=	-cblas
