# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/11 05:34:15 phonohawk Exp $

BUILDLINK_TREE+=	hs-hxt-relaxng

.if !defined(HS_HXT_RELAXNG_BUILDLINK3_MK)
HS_HXT_RELAXNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-relaxng+=	hs-hxt-relaxng>=9.1.4
BUILDLINK_PKGSRCDIR.hs-hxt-relaxng?=	../../wip/hs-hxt-relaxng

.include "../../wip/hs-hxt/buildlink3.mk"
.include "../../wip/hs-hxt-charproperties/buildlink3.mk"
.include "../../wip/hs-hxt-regex-xmlschema/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_RELAXNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-relaxng
