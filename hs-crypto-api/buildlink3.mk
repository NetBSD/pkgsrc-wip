# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 08:14:38 phonohawk Exp $

BUILDLINK_TREE+=	hs-crypto-api

.if !defined(HS_CRYPTO_API_BUILDLINK3_MK)
HS_CRYPTO_API_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypto-api+=	hs-crypto-api>=0.9
BUILDLINK_PKGSRCDIR.hs-crypto-api?=	../../wip/hs-crypto-api

.include "../../wip/hs-cereal/buildlink3.mk"
.include "../../wip/hs-entropy/buildlink3.mk"
.include "../../wip/hs-largeword/buildlink3.mk"
.include "../../wip/hs-tagged/buildlink3.mk"
.endif	# HS_CRYPTO_API_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypto-api
