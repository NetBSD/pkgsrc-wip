# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 07:44:46 phonohawk Exp $

BUILDLINK_TREE+=	hs-vty

.if !defined(HS_VTY_BUILDLINK3_MK)
HS_VTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vty+=	hs-vty>=4.7.0
BUILDLINK_PKGSRCDIR.hs-vty?=	../../wip/hs-vty

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parallel/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-terminfo/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_VTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vty
