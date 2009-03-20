# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:38 jsonn Exp $

BUILDLINK_TREE+=	FileManip

.if !defined(FILEMANIP_BUILDLINK3_MK)
FILEMANIP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.FileManip?=	build
BUILDLINK_API_DEPENDS.FileManip+=	FileManip>=0.3.2nb1
BUILDLINK_PKGSRCDIR.FileManip?=	../../wip/FileManip

.include "../../wip/hs-mtl/buildlink3.mk"
.endif # FILEMANIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-FileManip
