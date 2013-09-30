# $NetBSD: buildlink3.mk,v 1.6 2013/09/30 16:34:37 phonohawk Exp $

BUILDLINK_TREE+=	hs-HsSVN

.if !defined(HS_HSSVN_BUILDLINK3_MK)
HS_HSSVN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsSVN+=	hs-HsSVN>=0.4.3
BUILDLINK_PKGSRCDIR.hs-HsSVN?=	../../wip/hs-HsSVN

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-stm/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.endif	# HS_HSSVN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsSVN
