# $NetBSD: buildlink3.mk,v 1.2 2012/03/27 17:48:00 outpaddling Exp $

BUILDLINK_TREE+=	suitesparse

.if !defined(SUITESPARSE_BUILDLINK3_MK)
SUITESPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.suitesparse+=	suitesparse>=3.6.1
BUILDLINK_PKGSRCDIR.suitesparse?=	../../wip/suitesparse

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../wip/metis/buildlink3.mk"
.endif	# SUITESPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-suitesparse
