# $NetBSD: buildlink3.mk,v 1.3 2012/02/11 04:40:42 phonohawk Exp $

BUILDLINK_TREE+=	hs-hxt-xpath

.if !defined(HS_HXT_XPATH_BUILDLINK3_MK)
HS_HXT_XPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-xpath+=	hs-hxt-xpath>=9.1.2
BUILDLINK_PKGSRCDIR.hs-hxt-xpath?=	../../wip/hs-hxt-xpath

.include "../../wip/hs-hxt/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_XPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-xpath
