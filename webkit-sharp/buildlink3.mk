# $NetBSD: buildlink3.mk,v 1.1 2009/03/15 14:40:31 jihbed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WEBKIT_SHARP_BUILDLINK3_MK:=	${WEBKIT_SHARP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	webkit-sharp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwebkit-sharp}
BUILDLINK_PACKAGES+=	webkit-sharp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}webkit-sharp

.if ${WEBKIT_SHARP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.webkit-sharp+=	webkit-sharp>=0.2
BUILDLINK_PKGSRCDIR.webkit-sharp?=	../../wip/webkit-sharp
.endif	# WEBKIT_SHARP_BUILDLINK3_MK

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
