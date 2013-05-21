# $NetBSD: buildlink3.mk,v 1.2 2013/05/21 12:09:03 szptvlfn Exp $

BUILDLINK_TREE+=	hs-semigroupoids

.if !defined(HS_SEMIGROUPOIDS_BUILDLINK3_MK)
HS_SEMIGROUPOIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroupoids+=	hs-semigroupoids>=3.0.2
BUILDLINK_PKGSRCDIR.hs-semigroupoids?=	../../wip/hs-semigroupoids

.include "../../wip/hs-comonad/buildlink3.mk"
.include "../../wip/hs-contravariant/buildlink3.mk"
.include "../../wip/hs-semigroups/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_SEMIGROUPOIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroupoids
