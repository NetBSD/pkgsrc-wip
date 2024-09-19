# $NetBSD: buildlink3.mk,v 1.7 2014/08/29 14:10:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HsHyperEstraier

.if !defined(HS_HSHYPERESTRAIER_BUILDLINK3_MK)
HS_HSHYPERESTRAIER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsHyperEstraier+=	hs-HsHyperEstraier>=0.4
BUILDLINK_ABI_DEPENDS.hs-HsHyperEstraier+=	hs-HsHyperEstraier>=0.4
BUILDLINK_PKGSRCDIR.hs-HsHyperEstraier?=	../../wip/hs-HsHyperEstraier

.include "../../textproc/hyperestraier/buildlink3.mk"
.include "../../devel/hs-base-unicode-symbols/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_HSHYPERESTRAIER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsHyperEstraier
