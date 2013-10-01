# $NetBSD: buildlink3.mk,v 1.6 2013/10/01 01:41:18 phonohawk Exp $

BUILDLINK_TREE+=	hs-curl

.if !defined(HS_CURL_BUILDLINK3_MK)
HS_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-curl+=	hs-curl>=1.3.8
BUILDLINK_PKGSRCDIR.hs-curl?=	../../wip/hs-curl

.include "../../www/curl/buildlink3.mk"
.endif	# HS_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-curl
