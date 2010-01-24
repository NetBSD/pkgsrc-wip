# $NetBSD: buildlink3.mk,v 1.4 2010/01/24 03:40:21 phonohawk Exp $

BUILDLINK_TREE+=	hs-HDBC

.if !defined(HS_HDBC_BUILDLINK3_MK)
HS_HDBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HDBC+=	hs-HDBC>=2.1.1
BUILDLINK_PKGSRCDIR.hs-HDBC?=	../../wip/hs-HDBC

.include "../../wip/hs-convertible/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_HDBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HDBC
