# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-time-http

.if !defined(HS_TIME_HTTP_BUILDLINK3_MK)
HS_TIME_HTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-http+=	hs-time-http>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-time-http+=	hs-time-http>=0.1.0.1nb1
BUILDLINK_PKGSRCDIR.hs-time-http?=	../../wip/hs-time-http

.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_TIME_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-http
