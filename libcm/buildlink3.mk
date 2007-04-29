# $NetBSD: buildlink3.mk,v 1.1 2007/04/29 17:08:50 bsadewitz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCM_BUILDLINK3_MK:=	${LIBCM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libcm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcm}
BUILDLINK_PACKAGES+=	libcm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libcm

.if ${LIBCM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libcm+=	libcm>=0.1.1
BUILDLINK_PKGSRCDIR.libcm?=	../../wip/libcm
.endif	# LIBCM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
