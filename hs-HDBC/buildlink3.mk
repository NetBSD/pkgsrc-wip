# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/29 05:32:31 phonohawk Exp $

BUILDLINK_TREE+=	hs-HDBC

.if !defined(HS_HDBC_BUILDLINK3_MK)
HS_HDBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HDBC+=	hs-HDBC>=2.1.0
BUILDLINK_PKGSRCDIR.hs-HDBC?=	../../wip/hs-HDBC

.include "../../wip/hs-convertible/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.endif	# HS_HDBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HDBC
