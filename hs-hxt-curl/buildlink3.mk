# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:24 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hxt-curl

.if !defined(HS_HXT_CURL_BUILDLINK3_MK)
HS_HXT_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-curl+=	hs-hxt-curl>=9.1.1
BUILDLINK_ABI_DEPENDS.hs-hxt-curl+=	hs-hxt-curl>=9.1.1
BUILDLINK_PKGSRCDIR.hs-hxt-curl?=	../../wip/hs-hxt-curl

.include "../../wip/hs-curl/buildlink3.mk"
.include "../../textproc/hs-hxt/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-curl
