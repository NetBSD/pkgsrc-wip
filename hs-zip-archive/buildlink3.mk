# $NetBSD: buildlink3.mk,v 1.2 2013/08/21 20:42:22 szptvlfn Exp $

BUILDLINK_TREE+=	hs-zip-archive

.if !defined(HS_ZIP_ARCHIVE_BUILDLINK3_MK)
HS_ZIP_ARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zip-archive+=	hs-zip-archive>=0.1.3.4
BUILDLINK_PKGSRCDIR.hs-zip-archive?=	../../wip/hs-zip-archive
.endif	# HS_ZIP_ARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zip-archive
