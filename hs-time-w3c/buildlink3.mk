# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/16 04:48:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-time-w3c

.if !defined(HS_TIME_W3C_BUILDLINK3_MK)
HS_TIME_W3C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-w3c+=	hs-time-w3c>=0.1
BUILDLINK_PKGSRCDIR.hs-time-w3c?=	../../wip/hs-time-w3c

.include "../../wip/hs-convertible/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_TIME_W3C_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-w3c
