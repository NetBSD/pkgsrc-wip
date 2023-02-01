# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-pointed

.if !defined(HS_POINTED_BUILDLINK3_MK)
HS_POINTED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pointed+=	hs-pointed>=2.0.3
BUILDLINK_ABI_DEPENDS.hs-pointed+=	hs-pointed>=2.0.3
BUILDLINK_PKGSRCDIR.hs-pointed?=	../../wip/hs-pointed

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../wip/hs-comonad-transformers/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../wip/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-stm/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_POINTED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pointed
