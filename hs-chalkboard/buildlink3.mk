# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-chalkboard

.if !defined(HS_CHALKBOARD_BUILDLINK3_MK)
HS_CHALKBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-chalkboard+=	hs-chalkboard>=0.2
BUILDLINK_ABI_DEPENDS.hs-chalkboard+=	hs-chalkboard>=0.2
BUILDLINK_PKGSRCDIR.hs-chalkboard?=	../../wip/hs-chalkboard
.endif	# HS_CHALKBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-chalkboard
