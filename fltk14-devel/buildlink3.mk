# $NetBSD: buildlink3.mk,v 1.11 2018/03/12 11:15:49 wiz Exp $

BUILDLINK_TREE+=	fltk

.if !defined(FLTK_BUILDLINK3_MK)
FLTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fltk+=	fltk>=1.4.0
BUILDLINK_ABI_DEPENDS.fltk?=	fltk>=1.4.0
BUILDLINK_PKGSRCDIR.fltk?=	../../wip/fltk14-devel
BUILDLINK_FILES.fltk+=		include/Fl/*

pkgbase := fltk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.fltk:Mcairo)
.  include "../../graphics/cairo/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.fltk:Mopengl)
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/Mesa/buildlink3.mk"
.  endif
.endif

.if !empty(PKG_BUILD_OPTIONS.fltk:Mpango)
.  include "../../devel/pango/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXft/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # FLTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk
