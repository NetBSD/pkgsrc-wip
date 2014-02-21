# $NetBSD: buildlink3.mk,v 1.2 2014/02/21 10:39:02 szptvlfn Exp $

BUILDLINK_TREE+=	hs-timezone-olson

.if !defined(HS_TIMEZONE_OLSON_BUILDLINK3_MK)
HS_TIMEZONE_OLSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-timezone-olson+=	hs-timezone-olson>=0.1.2
BUILDLINK_PKGSRCDIR.hs-timezone-olson?=	../../wip/hs-timezone-olson

.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-timezone-series/buildlink3.mk"
.endif	# HS_TIMEZONE_OLSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-timezone-olson
