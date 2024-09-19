# $NetBSD: buildlink3.mk,v 1.7 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vty

.if !defined(HS_VTY_BUILDLINK3_MK)
HS_VTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vty+=	hs-vty>=4.7.0
BUILDLINK_ABI_DEPENDS.hs-vty+=	hs-vty>=4.7.0.10
BUILDLINK_PKGSRCDIR.hs-vty?=	../../wip/hs-vty

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-parallel/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../wip/hs-terminfo/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vty
