# $NetBSD: buildlink3.mk,v 1.1 2014/05/04 03:20:45 othyro Exp $

BUILDLINK_TREE+=	libarchive

.if !defined(LIBARCHIVE_BUILDLINK3_MK)
LIBARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.1.2
BUILDLINK_PKGSRCDIR.libarchive?=	../../wip/libarchive

.include "../../security/nettle/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libarchive
