# $NetBSD: MesaLib-replacement_buildlink3.mk,v 1.1 2007/07/18 19:23:32 bsadewitz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MESALIB_BUILDLINK3_MK:=	${MESALIB_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	MesaLib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NMesaLib}
BUILDLINK_PACKAGES+=	MesaLib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}MesaLib

.if ${MESALIB_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=6.4.1
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=7.0nb2
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib
BUILDLINK_TRANSFORM+=		l:MesaGL:GL
BUILDLINK_TRANSFORM+=		l:GL:GL:Xxf86vm:Xfixes:Xdamage:drm
.endif	# MESALIB_BUILDLINK3_MK

.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
