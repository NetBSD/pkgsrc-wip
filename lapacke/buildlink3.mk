# $NetBSD$

BUILDLINK_TREE+=	lapacke

.if !defined(LAPACKE_BUILDLINK3_MK)
LAPACKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapacke+=	lapacke>=3.9.0
BUILDLINK_PKGSRCDIR.lapacke?=	../../wip/lapacke

.include	"../../wip/mk/blas.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-lapacke
