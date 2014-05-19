# $NetBSD: buildlink3.mk,v 1.2 2014/05/19 21:28:49 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hxt-xslt

.if !defined(HS_HXT_XSLT_BUILDLINK3_MK)
HS_HXT_XSLT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-xslt+=	hs-hxt-xslt>=9.1.1
BUILDLINK_PKGSRCDIR.hs-hxt-xslt?=	../../wip/hs-hxt-xslt

.include "../../wip/hs-hxt/buildlink3.mk"
.include "../../wip/hs-hxt-xpath/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_XSLT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-xslt
