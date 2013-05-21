# $NetBSD: buildlink3.mk,v 1.1 2013/05/21 12:35:34 szptvlfn Exp $

BUILDLINK_TREE+=	hs-bifunctors

.if !defined(HS_BIFUNCTORS_BUILDLINK3_MK)
HS_BIFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bifunctors+=	hs-bifunctors>=3.2.0
BUILDLINK_PKGSRCDIR.hs-bifunctors?=	../../wip/hs-bifunctors

.endif	# HS_BIFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bifunctors
