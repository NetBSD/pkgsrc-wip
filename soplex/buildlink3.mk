# $NetBSD$

BUILDLINK_TREE+=	soplex

.if !defined(SOPLEX_BUILDLINK3_MK)
SOPLEX_BUILDLINK3_MK:=

BUILDLINK_FILES.soplex+=	bin/soplex

BUILDLINK_API_DEPENDS.soplex+=	soplex>=7.1.0.0
BUILDLINK_PKGSRCDIR.soplex?=	../../wip/soplex

.include "../../math/mpfr/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif	# SOPLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-soplex
