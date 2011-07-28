# $NetBSD: buildlink3.mk,v 1.5 2011/07/28 09:40:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-HsSVN

.if !defined(HS_HSSVN_BUILDLINK3_MK)
HS_HSSVN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsSVN+=	hs-HsSVN>=0.4
BUILDLINK_PKGSRCDIR.hs-HsSVN?=	../../wip/hs-HsSVN

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-stm/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.endif	# HS_HSSVN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsSVN
