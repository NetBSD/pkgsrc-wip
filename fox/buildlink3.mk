# $NetBSD$

BUILDLINK_TREE+=	fox

.if !defined(FOX_BUILDLINK3_MK)
FOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fox+=	fox>=1.7.79
BUILDLINK_ABI_DEPENDS.fox+=	fox>=1.7.79
BUILDLINK_PKGSRCDIR.fox?=	../../x11/fox
BUILDLINK_INCDIRS.fox?=		include/fox-1.7

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # FOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-fox
