# $NetBSD: buildlink3.mk,v 1.11 2014/03/16 12:21:08 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cpphs

.if !defined(HS_CPPHS_BUILDLINK3_MK)
HS_CPPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cpphs+=	hs-cpphs>=1.18.3
BUILDLINK_PKGSRCDIR.hs-cpphs?=	../../wip/hs-cpphs

.include "../../wip/hs-polyparse/buildlink3.mk"
.endif	# HS_CPPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cpphs
