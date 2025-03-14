# $NetBSD$

BUILDLINK_TREE+=	fltk11

.if !defined(FLTK11_BUILDLINK3_MK)
FLTK11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fltk11+=	fltk11>=1.1.5rc1<1.3
BUILDLINK_ABI_DEPENDS.fltk11?=	fltk11>=1.1.10nb7<1.3
BUILDLINK_PKGSRCDIR.fltk11?=	../../wip/fltk11
BUILDLINK_FILES.fltk11+=	include/Fl/*

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif # FLTK11_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk11
