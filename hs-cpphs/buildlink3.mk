# $NetBSD: buildlink3.mk,v 1.10 2014/02/18 14:27:19 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.18.1
BUILDLINK_PKGSRCDIR.hs-cpphs?=	../../wip/hs-cpphs
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
