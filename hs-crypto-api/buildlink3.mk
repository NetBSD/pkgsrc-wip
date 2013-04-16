# $NetBSD: buildlink3.mk,v 1.3 2013/04/16 11:06:42 szptvlfn Exp $

BUILDLINK_TREE+=	hs-crypto-api

.if !defined(HS_CRYPTO_API_BUILDLINK3_MK)
HS_CRYPTO_API_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypto-api+=	hs-crypto-api>=0.11
BUILDLINK_PKGSRCDIR.hs-crypto-api?=	../../wip/hs-crypto-api

.endif	# HS_CRYPTO_API_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypto-api
