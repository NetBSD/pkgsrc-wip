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

# For "opengl" option
.if ${PKG_BUILD_OPTIONS.fltk:Mopengl}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../graphics/MesaLib/buildlink3.mk"
.    include "../../graphics/glu/buildlink3.mk"
.  endif
.endif

# For "pango" option
.if ${PKG_BUILD_OPTIONS.fltk:Mpango}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../devel/pango/buildlink3.mk"
.  endif
.endif

# For "x11" option
.if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXcursor/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXfixes/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.endif

# For "xdbe" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxdbe}
# No client library required
.endif

# For "xft2" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxft2}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../x11/libXft/buildlink3.mk"
.  endif
.endif

# For "xinerama" option
.if ${PKG_BUILD_OPTIONS.fltk:Mxinerama}
.  if ${PKG_BUILD_OPTIONS.fltk:Mx11}
.    include "../../x11/libXinerama/buildlink3.mk"
.  endif
.endif

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # FLTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk
