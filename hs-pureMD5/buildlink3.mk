# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 07:43:06 phonohawk Exp $

BUILDLINK_TREE+=	hs-pureMD5

.if !defined(HS_PUREMD5_BUILDLINK3_MK)
HS_PUREMD5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pureMD5+=	hs-pureMD5>=2.1
BUILDLINK_PKGSRCDIR.hs-pureMD5?=	../../wip/hs-pureMD5

.include "../../wip/hs-binary/buildlink3.mk"
.include "../../wip/hs-cereal/buildlink3.mk"
.include "../../wip/hs-crypto-api/buildlink3.mk"
.include "../../wip/hs-tagged/buildlink3.mk"
.endif	# HS_PUREMD5_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pureMD5
