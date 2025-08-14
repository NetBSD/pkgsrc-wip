# $NetBSD$

BUILDLINK_TREE+=	libzim

.if !defined(LIBZIM_BUILDLINK3_MK)
LIBZIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzim+=	libzim>=9.3.0
BUILDLINK_PKGSRCDIR.libzim?=	../../wip/libzim

.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.endif	# LIBZIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzim
