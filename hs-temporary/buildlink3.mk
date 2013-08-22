# $NetBSD: buildlink3.mk,v 1.1 2013/08/22 23:11:16 szptvlfn Exp $

BUILDLINK_TREE+=	hs-temporary

.if !defined(HS_TEMPORARY_BUILDLINK3_MK)
HS_TEMPORARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-temporary+=	hs-temporary>=1.1.2.4
BUILDLINK_PKGSRCDIR.hs-temporary?=	../../wip/hs-temporary
.endif	# HS_TEMPORARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-temporary
