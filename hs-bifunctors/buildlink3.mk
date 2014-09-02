# $NetBSD: buildlink3.mk,v 1.6 2014/09/02 21:00:52 szptvlfn Exp $

BUILDLINK_TREE+=	hs-bifunctors

.if !defined(HS_BIFUNCTORS_BUILDLINK3_MK)
HS_BIFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bifunctors+=	hs-bifunctors>=4.1.1
BUILDLINK_ABI_DEPENDS.hs-bifunctors+=	hs-bifunctors>=4.1.1.1
BUILDLINK_PKGSRCDIR.hs-bifunctors?=	../../wip/hs-bifunctors

.include "../../wip/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_BIFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bifunctors
