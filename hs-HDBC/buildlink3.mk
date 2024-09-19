# $NetBSD: buildlink3.mk,v 1.8 2014/08/29 14:10:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HDBC

.if !defined(HS_HDBC_BUILDLINK3_MK)
HS_HDBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HDBC+=	hs-HDBC>=2.2.6
BUILDLINK_ABI_DEPENDS.hs-HDBC+=	hs-HDBC>=2.2.6
BUILDLINK_PKGSRCDIR.hs-HDBC?=	../../wip/hs-HDBC

.include "../../wip/hs-convertible/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_HDBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HDBC
