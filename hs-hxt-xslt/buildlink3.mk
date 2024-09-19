# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hxt-xslt

.if !defined(HS_HXT_XSLT_BUILDLINK3_MK)
HS_HXT_XSLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-xslt+=	hs-hxt-xslt>=9.1.1
BUILDLINK_ABI_DEPENDS.hs-hxt-xslt+=	hs-hxt-xslt>=9.1.1
BUILDLINK_PKGSRCDIR.hs-hxt-xslt?=	../../wip/hs-hxt-xslt

.include "../../textproc/hs-hxt/buildlink3.mk"
.include "../../wip/hs-hxt-xpath/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_XSLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-xslt
