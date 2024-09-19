# $NetBSD$

BUILDLINK_TREE+=	bertini

.if !defined(BERTINI_BUILDLINK3_MK)
BERTINI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bertini+=	bertini>=1.5
BUILDLINK_PKGSRCDIR.bertini?=	../../wip/bertini

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.endif	# BERTINI_BUILDLINK3_MK

BUILDLINK_TREE+=	-bertini
