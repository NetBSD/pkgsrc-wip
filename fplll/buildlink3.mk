# $NetBSD$

BUILDLINK_TREE+=	fplll

.if !defined(FPLLL_BUILDLINK3_MK)
FPLLL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fplll+=	fplll>=5.2.0
BUILDLINK_PKGSRCDIR.fplll?=	../../wip/fplll


.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.endif	# FPLLL_BUILDLINK3_MK

BUILDLINK_TREE+=	-fplll
