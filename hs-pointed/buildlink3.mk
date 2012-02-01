# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/01 16:44:37 phonohawk Exp $

BUILDLINK_TREE+=	hs-pointed

.if !defined(HS_POINTED_BUILDLINK3_MK)
HS_POINTED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pointed+=	hs-pointed>=2.0.3
BUILDLINK_PKGSRCDIR.hs-pointed?=	../../wip/hs-pointed

.include "../../wip/hs-comonad/buildlink3.mk"
.include "../../wip/hs-comonad-transformers/buildlink3.mk"
.include "../../wip/hs-data-default/buildlink3.mk"
.include "../../wip/hs-semigroupoids/buildlink3.mk"
.include "../../wip/hs-stm/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_POINTED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pointed
