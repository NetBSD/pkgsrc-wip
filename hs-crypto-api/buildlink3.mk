# $NetBSD: buildlink3.mk,v 1.9 2014/08/29 14:10:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-crypto-api

.if !defined(HS_CRYPTO_API_BUILDLINK3_MK)
HS_CRYPTO_API_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypto-api+=	hs-crypto-api>=0.13
BUILDLINK_ABI_DEPENDS.hs-crypto-api+=	hs-crypto-api>=0.13
BUILDLINK_PKGSRCDIR.hs-crypto-api?=	../../wip/hs-crypto-api

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_CRYPTO_API_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypto-api
