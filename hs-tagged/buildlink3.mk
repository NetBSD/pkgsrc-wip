# $NetBSD: buildlink3.mk,v 1.4 2013/04/16 11:51:45 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.4.5
BUILDLINK_PKGSRCDIR.hs-tagged?=	../../wip/hs-tagged

.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
