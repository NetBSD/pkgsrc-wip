# $NetBSD$

BUILDLINK_TREE+=	fltk

.if !defined(FLTK_BUILDLINK3_MK)
FLTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fltk+=	fltk>=1.4.0
BUILDLINK_ABI_DEPENDS.fltk?=	fltk>=1.4.0
BUILDLINK_PKGSRCDIR.fltk?=	../../wip/fltk14-devel
BUILDLINK_FILES.fltk+=		include/Fl/*

pkgbase := fltk
.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/pkg-build-options.mk"

# For "cairo" option
.if !empty(PKG_BUILD_OPTIONS.fltk:Mcairo)
.  include "../../graphics/cairo/buildlink3.mk"
.endif

# For "opengl" option
.if !empty(PKG_BUILD_OPTIONS.fltk:Mopengl)
.  if ${OPSYS} != "Darwin"
.     include "../../graphics/MesaLib/buildlink3.mk"
.     include "../../graphics/glu/buildlink3.mk"
.  endif
.endif

# For "pango" option
.if !empty(PKG_BUILD_OPTIONS.fltk:Mpango)
.  if ${OPSYS} != "Darwin"
# Untested: Cocoa backend on macOS should use Core Text instead
.     include "../../devel/pango/buildlink3.mk"
.  endif
.endif

.if ${OPSYS} != "Darwin"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXft/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # FLTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk
