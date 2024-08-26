# $NetBSD$

BUILDLINK_TREE+=	scip

.if !defined(SCIP_BUILDLINK3_MK)
SCIP_BUILDLINK3_MK:=

BUILDLINK_FILES.scip+=	bin/scip

BUILDLINK_API_DEPENDS.scip+=	scip>=9.1.0
BUILDLINK_PKGSRCDIR.scip?=	../../wip/scip

.include "../../wip/soplex/buildlink3.mk"
.include "../../math/ipopt/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif	# SCIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-scip
