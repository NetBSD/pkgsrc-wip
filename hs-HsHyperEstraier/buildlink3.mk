# $NetBSD: buildlink3.mk,v 1.4 2011/07/28 10:20:19 phonohawk Exp $

BUILDLINK_TREE+=	hs-HsHyperEstraier

.if !defined(HS_HSHYPERESTRAIER_BUILDLINK3_MK)
HS_HSHYPERESTRAIER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsHyperEstraier+=	hs-HsHyperEstraier>=0.4
BUILDLINK_PKGSRCDIR.hs-HsHyperEstraier?=	../../wip/hs-HsHyperEstraier

.include "../../textproc/hyperestraier/buildlink3.mk"
.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_HSHYPERESTRAIER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsHyperEstraier
