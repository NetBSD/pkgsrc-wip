# $NetBSD: buildlink3.mk,v 1.2 2013/10/14 10:48:50 szptvlfn Exp $

BUILDLINK_TREE+=	hs-bifunctors

.if !defined(HS_BIFUNCTORS_BUILDLINK3_MK)
HS_BIFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bifunctors+=	hs-bifunctors>=4.1
BUILDLINK_PKGSRCDIR.hs-bifunctors?=	../../wip/hs-bifunctors

.include "../../wip/hs-semigroupoids/buildlink3.mk"
.include "../../wip/hs-semigroups/buildlink3.mk"
.include "../../wip/hs-tagged/buildlink3.mk"
.endif	# HS_BIFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bifunctors
