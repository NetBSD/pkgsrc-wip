# $NetBSD: buildlink3.mk,v 1.9 2014/08/29 14:10:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HsSVN

.if !defined(HS_HSSVN_BUILDLINK3_MK)
HS_HSSVN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsSVN+=	hs-HsSVN>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-HsSVN+=	hs-HsSVN>=0.4.3.3
BUILDLINK_PKGSRCDIR.hs-HsSVN?=		../../wip/hs-HsSVN

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-stm/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.endif	# HS_HSSVN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsSVN
