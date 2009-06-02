# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/02 07:43:45 phonohawk Exp $

BUILDLINK_TREE+=	hs-hxt

.if !defined(HS_HXT_BUILDLINK3_MK)
HS_HXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt+=	hs-hxt>=8.3.0
BUILDLINK_PKGSRCDIR.hs-hxt?=	../../wip/hs-hxt

.include "../../wip/hs-HUnit/buildlink3.mk"
.include "../../wip/hs-curl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-parallel/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-tagsoup/buildlink3.mk"
.endif	# HS_HXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt
