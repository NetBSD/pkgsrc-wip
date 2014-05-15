# $NetBSD: buildlink3.mk,v 1.2 2014/05/15 21:49:10 szptvlfn Exp $

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
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_POINTED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pointed
