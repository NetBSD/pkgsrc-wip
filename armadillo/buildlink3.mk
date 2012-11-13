# $NetBSD: buildlink3.mk,v 1.4 2012/11/13 23:56:10 outpaddling Exp $

BUILDLINK_TREE+=	armadillo

.if !defined(ARMADILLO_BUILDLINK3_MK)
ARMADILLO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.armadillo+=	armadillo>=3.4.4
BUILDLINK_ABI_DEPENDS.armadillo?=	armadillo>=3.4.4
BUILDLINK_PKGSRCDIR.armadillo?=	../../math/armadillo

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.endif	# ARMADILLO_BUILDLINK3_MK

BUILDLINK_TREE+=	-armadillo
