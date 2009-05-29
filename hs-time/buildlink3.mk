# $NetBSD: buildlink3.mk,v 1.3 2009/05/29 04:44:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-time

.if !defined(HS_TIME_BUILDLINK3_MK)
HS_TIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time+=	hs-time>=1.1.2.4
BUILDLINK_PKGSRCDIR.hs-time?=	../../wip/hs-time
.endif	# HS_TIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time
