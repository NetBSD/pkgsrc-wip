# $NetBSD: buildlink3.mk,v 1.7 2014/10/02 15:31:39 uccwen Exp $

BUILDLINK_TREE+=	armadillo

.if !defined(ARMADILLO_BUILDLINK3_MK)
ARMADILLO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.armadillo+=	armadillo>=4.45.2
BUILDLINK_ABI_DEPENDS.armadillo?=	armadillo>=4.45.2
BUILDLINK_PKGSRCDIR.armadillo?=		../../wip/armadillo

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.endif	# ARMADILLO_BUILDLINK3_MK

BUILDLINK_TREE+=	-armadillo
