# $NetBSD: buildlink3.mk,v 1.1 2013/10/18 10:16:13 fhajny Exp $

BUILDLINK_TREE+=	spread

.if !defined(SPREAD_BUILDLINK3_MK)
SPREAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spread+=	spread>=4.3.0
BUILDLINK_PKGSRCDIR.spread?=	../../net/spread
BUILDLINK_INCDIRS.spread?=	include/spread
.endif # SPREAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-spread
