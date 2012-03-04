# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 08:17:53 phonohawk Exp $

BUILDLINK_TREE+=	hs-pureMD5

.if !defined(HS_PUREMD5_BUILDLINK3_MK)
HS_PUREMD5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pureMD5+=	hs-pureMD5>=2.1.0
BUILDLINK_PKGSRCDIR.hs-pureMD5?=	../../wip/hs-pureMD5

.include "../../wip/hs-cereal/buildlink3.mk"
.include "../../wip/hs-crypto-api/buildlink3.mk"
.include "../../wip/hs-tagged/buildlink3.mk"
.endif	# HS_PUREMD5_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pureMD5
