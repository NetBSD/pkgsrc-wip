# $NetBSD: buildlink3.mk,v 1.5 2010/01/17 12:03:26 thomasklausner Exp $

BUILDLINK_TREE+=	hs-curl

.if !defined(HS_CURL_BUILDLINK3_MK)
HS_CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-curl+=	hs-curl>=1.3.5
BUILDLINK_ABI_DEPENDS.hs-curl?=	hs-curl>=1.3.5nb1
BUILDLINK_PKGSRCDIR.hs-curl?=	../../wip/hs-curl

.include "../../www/curl/buildlink3.mk"
.endif	# HS_CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-curl
