# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:17 szptvlfn Exp $

BUILDLINK_TREE+=	hs-haskelldb-hdbc

.if !defined(HS_HASKELLDB_HDBC_BUILDLINK3_MK)
HS_HASKELLDB_HDBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskelldb-hdbc+=	hs-haskelldb-hdbc>=0.13
BUILDLINK_ABI_DEPENDS.hs-haskelldb-hdbc+=	hs-haskelldb-hdbc>=0.13
BUILDLINK_PKGSRCDIR.hs-haskelldb-hdbc?=		../../wip/hs-haskelldb-hdbc

.include "../../wip/hs-convertible/buildlink3.mk"
.include "../../wip/hs-haskelldb/buildlink3.mk"
.include "../../wip/hs-HDBC/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_HASKELLDB_HDBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskelldb-hdbc
