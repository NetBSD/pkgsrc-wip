# $NetBSD: buildlink3.mk,v 1.24 2013/08/28 16:51:36 richard Exp $

BUILDLINK_TREE+=	compat32_tiff

.if !defined(COMPAT32_TIFF_BUILDLINK3_MK)
COMPAT32_TIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_tiff+=	compat32_tiff>=3.6.1
BUILDLINK_ABI_DEPENDS.compat32_tiff+=	compat32_tiff>=4.0.3nb5
BUILDLINK_PKGSRCDIR.compat32_tiff?=	../../wip/compat32_tiff
BUILDLINK_LIBDIRS.compat32_tiff=	emul/netbsd32/lib
BUILDLINK_INCDIRS.compat32_tiff=	emul/netbsd32/include

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # COMPAT32_TIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_tiff
