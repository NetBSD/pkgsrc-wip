# $NetBSD: buildlink3.mk,v 1.1 2013/08/31 08:27:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-semigroupoid-extras

.if !defined(HS_SEMIGROUPOID_EXTRAS_BUILDLINK3_MK)
HS_SEMIGROUPOID_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-semigroupoid-extras+=	hs-semigroupoid-extras>=3.0.1
BUILDLINK_PKGSRCDIR.hs-semigroupoid-extras?=	../../wip/hs-semigroupoid-extras

.endif	# HS_SEMIGROUPOID_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-semigroupoid-extras
