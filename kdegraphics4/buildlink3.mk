# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	kdegraphics4

.if !defined(KDEGRAPHICS4_BUILDLINK3_MK)
KDEGRAPHICS4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegraphics4+=	kdegraphics4>=4.1.1
BUILDLINK_ABI_DEPENDS.kdegraphics4?=	kdegraphics4>=4.1.3nb1
BUILDLINK_PKGSRCDIR.kdegraphics4?=	../../wip/kdegraphics4

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/chmlib/buildlink3.mk"
#.include "../../devel/libgphoto2/buildlink3.mk"
#.include "../../graphics/djvulibre-lib/buildlink3.mk"
#.include "../../graphics/exiv2/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
#.include "../../print/libspectre/buildlink3.mk"
#.include "../../print/poppler-qt4/buildlink3.mk"
#.include "../../security/qca2/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
#.include "../../wip/kdebase-runtime4/buildlink3.mk"
#.include "../../wip/qimageblitz/buildlink3.mk"
#.include "../../x11/libXxf86vm/buildlink3.mk"
.endif # KDEGRAPHICS4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegraphics4
