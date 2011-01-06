# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/06 13:07:28 phonohawk Exp $

BUILDLINK_TREE+=	hs-strict

.if !defined(HS_STRICT_BUILDLINK3_MK)
HS_STRICT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-strict+=	hs-strict>=0.3
BUILDLINK_PKGSRCDIR.hs-strict?=	../../wip/hs-strict
.endif	# HS_STRICT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-strict
