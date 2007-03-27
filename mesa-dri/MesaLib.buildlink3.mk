# $NetBSD: MesaLib.buildlink3.mk,v 1.1.1.1 2007/03/27 22:28:19 dillo Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MESALIB_BUILDLINK3_MK:=	${MESALIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	MesaLib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NMesaLib}
BUILDLINK_PACKAGES+=	MesaLib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}MesaLib

.if !empty(MESALIB_BUILDLINK3_MK:M+)
#BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=3.4.2
#BUILDLINK_ABI_DEPENDS.MesaLib+=	MesaLib>=6.4.1nb1
#BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib
BUILDLINK_API_DEPENDS.MesaLib+=	mesa-dri>=3.4.2
BUILDLINK_ABI_DEPENDS.MesaLib+=	mesa-dri>=6.4.1nb1
BUILDLINK_PKGSRCDIR.MesaLib?=	../../wip/mesa-dri

.if !defined(BUILDING_MESA)
BUILDLINK_CPPFLAGS.MesaLib=	-DGLX_GLXEXT_LEGACY
.endif

BUILDLINK_TRANSFORM+=		l:MesaGL:GL:drm:Xxf86vm
BUILDLINK_TRANSFORM+=		l:GL:GL:drm:Xxf86vm
BUILDLINK_FILES.MesaLib+= lib/libdrm.* lib/libXxf86vm.*

.endif	# MESALIB_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.include "../../devel/pthread-stublib/buildlink3.mk"
.endif

.include "../../x11/libXext/buildlink3.mk"
#.include "../../x11/libXi/buildlink3.mk"
#.include "../../x11/libXdamage/buildlink3.mk"
#.include "../../x11/libXfixes/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
