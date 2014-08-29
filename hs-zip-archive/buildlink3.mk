# $NetBSD: buildlink3.mk,v 1.9 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-zip-archive

.if !defined(HS_ZIP_ARCHIVE_BUILDLINK3_MK)
HS_ZIP_ARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zip-archive+=	hs-zip-archive>=0.2
BUILDLINK_ABI_DEPENDS.hs-zip-archive+=	hs-zip-archive>=0.2
BUILDLINK_PKGSRCDIR.hs-zip-archive?=	../../wip/hs-zip-archive

.include "../../security/hs-digest/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_ZIP_ARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zip-archive
