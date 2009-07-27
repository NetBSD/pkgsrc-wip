# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/07/27 03:23:29 phonohawk Exp $

BUILDLINK_TREE+=	hs-FileManip

.if !defined(HS_FILEMANIP_BUILDLINK3_MK)
HS_FILEMANIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-FileManip+=	hs-FileManip>=0.3.2
BUILDLINK_PKGSRCDIR.hs-FileManip?=	../../wip/hs-FileManip

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_FILEMANIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-FileManip
