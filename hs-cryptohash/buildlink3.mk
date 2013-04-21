# $NetBSD: buildlink3.mk,v 1.1 2013/04/21 09:30:24 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cryptohash

.if !defined(HS_CRYPTOHASH_BUILDLINK3_MK)
HS_CRYPTOHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cryptohash+=	hs-cryptohash>=0.9.0
BUILDLINK_PKGSRCDIR.hs-cryptohash?=	../../wip/hs-cryptohash
.endif	# HS_CRYPTOHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cryptohash
