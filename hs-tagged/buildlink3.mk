# $NetBSD: buildlink3.mk,v 1.5 2014/05/08 00:33:47 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.7.2
BUILDLINK_PKGSRCDIR.hs-tagged?=	../../wip/hs-tagged
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
