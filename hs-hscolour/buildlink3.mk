# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/11/10 03:44:43 phonohawk Exp $

BUILDLINK_TREE+=	hs-hscolour

.if !defined(HS_HSCOLOUR_BUILDLINK3_MK)
HS_HSCOLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hscolour+=	hs-hscolour>=1.15
BUILDLINK_PKGSRCDIR.hs-hscolour?=	../../wip/hs-hscolour
.endif	# HS_HSCOLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hscolour
