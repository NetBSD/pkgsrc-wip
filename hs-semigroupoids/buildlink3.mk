# $NetBSD: buildlink3.mk,v 1.10 2014/09/03 21:16:18 szptvlfn Exp $

BUILDLINK_TREE+=	hs-semigroupoids

.if !defined(HS_SEMIGROUPOIDS_BUILDLINK3_MK)
HS_SEMIGROUPOIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroupoids+=	hs-semigroupoids>=4.2
BUILDLINK_ABI_DEPENDS.hs-semigroupoids+=	hs-semigroupoids>=4.2
BUILDLINK_PKGSRCDIR.hs-semigroupoids?=		../../wip/hs-semigroupoids

.include "../../wip/hs-comonad/buildlink3.mk"
.include "../../wip/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_SEMIGROUPOIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroupoids
