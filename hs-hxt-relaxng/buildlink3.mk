# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hxt-relaxng

.if !defined(HS_HXT_RELAXNG_BUILDLINK3_MK)
HS_HXT_RELAXNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-relaxng+=	hs-hxt-relaxng>=9.1.4
BUILDLINK_ABI_DEPENDS.hs-hxt-relaxng+=	hs-hxt-relaxng>=9.1.4
BUILDLINK_PKGSRCDIR.hs-hxt-relaxng?=	../../wip/hs-hxt-relaxng

.include "../../textproc/hs-hxt/buildlink3.mk"
.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.include "../../textproc/hs-hxt-regex-xmlschema/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_RELAXNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-relaxng
