# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-time-w3c

.if !defined(HS_TIME_W3C_BUILDLINK3_MK)
HS_TIME_W3C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-time-w3c+=	hs-time-w3c>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-time-w3c+=	hs-time-w3c>=0.1.0.1
BUILDLINK_PKGSRCDIR.hs-time-w3c?=	../../wip/hs-time-w3c

.include "../../wip/hs-convertible/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_TIME_W3C_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-time-w3c
