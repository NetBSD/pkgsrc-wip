# $NetBSD: buildlink3.mk,v 1.2 2013/10/01 10:12:25 phonohawk Exp $

BUILDLINK_TREE+=	hs-time-http

.if !defined(HS_TIME_HTTP_BUILDLINK3_MK)
HS_TIME_HTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-http+=	hs-time-http>=0.1.0
BUILDLINK_PKGSRCDIR.hs-time-http?=	../../wip/hs-time-http

.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_TIME_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-http
