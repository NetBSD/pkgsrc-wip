# $NetBSD$

BUILDLINK_TREE+=	flint

.if !defined(FLINT_BUILDLINK3_MK)
FLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flint+=	flint>=2.6.3
BUILDLINK_PKGSRCDIR.flint?=	../../wip/flint

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"

.endif	# FLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-flint
