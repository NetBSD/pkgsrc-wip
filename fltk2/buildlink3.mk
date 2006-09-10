# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/09/10 23:13:27 milosn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FLTK_BUILDLINK3_MK:=	${FLTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fltk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfltk2}
BUILDLINK_PACKAGES+=	fltk2

.if !empty(FLTK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.fltk2+=	fltk2>=5425
BUILDLINK_ABI_DEPENDS.fltk2+=	fltk2>=5425
BUILDLINK_PKGSRCDIR.fltk2?=	../../wip/fltk2
BUILDLINK_FILES.fltk2+=		include/fltk/*
.endif	# FLTK_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
