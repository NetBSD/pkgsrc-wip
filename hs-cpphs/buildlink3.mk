# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/03 07:23:50 phonohawk Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.6
BUILDLINK_PKGSRCDIR.hs-cpphs?=	../../wip/hs-cpphs
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
