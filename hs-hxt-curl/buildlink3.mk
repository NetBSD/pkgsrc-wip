# $NetBSD: buildlink3.mk,v 1.2 2014/05/19 21:28:48 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hxt-curl

.if !defined(HS_HXT_CURL_BUILDLINK3_MK)
HS_HXT_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-curl+=	hs-hxt-curl>=9.1.1
BUILDLINK_PKGSRCDIR.hs-hxt-curl?=	../../wip/hs-hxt-curl

.include "../../wip/hs-curl/buildlink3.mk"
.include "../../wip/hs-hxt/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-curl
