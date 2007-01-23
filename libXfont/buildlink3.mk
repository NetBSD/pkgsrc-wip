# $NetBSD: buildlink3.mk,v 1.9 2007/01/23 15:52:54 bsadewitz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFONT_BUILDLINK3_MK:=	${LIBXFONT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXfont
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXfont}
BUILDLINK_PACKAGES+=	libXfont
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXfont

.if ${LIBXFONT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXfont+=	libXfont>=1.2.7
BUILDLINK_PKGSRCDIR.libXfont?=	../../wip/libXfont
.endif	# LIBXFONT_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/libfontenc/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
