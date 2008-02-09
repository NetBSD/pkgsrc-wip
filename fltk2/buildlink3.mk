# $NetBSD: buildlink3.mk,v 1.2 2008/02/09 21:27:53 shattered Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FLTK2_BUILDLINK3_MK:=	${FLTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fltk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfltk2}
BUILDLINK_PACKAGES+=	fltk2

.if !empty(FLTK2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.fltk2+=	fltk2>=5425
BUILDLINK_ABI_DEPENDS.fltk2+=	fltk2>=5425
BUILDLINK_PKGSRCDIR.fltk2?=	../../wip/fltk2
BUILDLINK_FILES.fltk2+=		include/fltk/*
.endif	# FLTK2_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
