# $NetBSD$

BUILDLINK_TREE+=	fltk2

.if !defined(FLTK2_BUILDLINK3_MK)
FLTK2_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.fltk2?=	build
BUILDLINK_API_DEPENDS.fltk2+=	fltk2>=2.1git
BUILDLINK_ABI_DEPENDS.fltk2+=	fltk2>=2.1git
BUILDLINK_PKGSRCDIR.fltk2?=	../../wip/fltk2

pkgbase := fltk2
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.fltk2:Mopengl}
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.endif # FLTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk2
