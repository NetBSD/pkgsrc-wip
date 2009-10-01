# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/01 04:28:57 phonohawk Exp $

BUILDLINK_TREE+=	hs-MissingH

.if !defined(HS_MISSINGH_BUILDLINK3_MK)
HS_MISSINGH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MissingH+=	hs-MissingH>=1.1.0.1
BUILDLINK_PKGSRCDIR.hs-MissingH?=	../../wip/hs-MissingH

.include "../../wip/hs-HUnit/buildlink3.mk"
.include "../../wip/hs-QuickCheck1/buildlink3.mk"
.include "../../wip/hs-hslogger/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.endif	# HS_MISSINGH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MissingH
