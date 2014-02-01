# $NetBSD: buildlink3.mk,v 1.2 2014/02/01 10:10:33 szptvlfn Exp $

BUILDLINK_TREE+=	hs-safe

.if !defined(HS_SAFE_BUILDLINK3_MK)
HS_SAFE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safe+=	hs-safe>=0.3.4
BUILDLINK_PKGSRCDIR.hs-safe?=	../../wip/hs-safe
.endif	# HS_SAFE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safe
