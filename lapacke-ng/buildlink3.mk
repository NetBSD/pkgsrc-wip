# $NetBSD$

BUILDLINK_TREE+=	lapacke

.if !defined(CBLAS_BUILDLINK3_MK)
CBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas+=	cblas-ng>=3.8.0
BUILDLINK_PKGSRCDIR.lapacke?=	../../wip/lapacke-ng
BUILDLINK_DEPMETHOD.lapacke?=	full
.endif

BUILDLINK_TREE+=	-lapacke
