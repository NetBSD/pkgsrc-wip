# $NetBSD$

BUILDLINK_TREE+=	cblas

.if !defined(CBLAS_BUILDLINK3_MK)
CBLAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas+=	cblas>=3.9.0
BUILDLINK_PKGSRCDIR.cblas?=	../../wip/cblas

# Causes problems if cblas/bl3 is included before blas.bl3 in the pkg Makefile.
# Without this, they can be included in either order.
# I think pkg Makefiles should include both for clarity rather than have
# cblas implicitly pull in blas.bl3.
#.include	"../../wip/mk/blas.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-cblas
