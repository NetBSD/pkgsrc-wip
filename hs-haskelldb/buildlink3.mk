# $NetBSD: buildlink3.mk,v 1.2 2014/05/16 20:47:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-haskelldb

.if !defined(HS_HASKELLDB_BUILDLINK3_MK)
HS_HASKELLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskelldb+=	hs-haskelldb>=0.12
BUILDLINK_PKGSRCDIR.hs-haskelldb?=	../../wip/hs-haskelldb

.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_HASKELLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskelldb
