# $NetBSD: buildlink3.mk,v 1.4 2004/07/27 22:16:14 thomasklausner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTK_SHARP_BUILDLINK3_MK:=	${GTK_SHARP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk-sharp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk-sharp}
BUILDLINK_PACKAGES+=	gtk-sharp

.if !empty(GTK_SHARP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtk-sharp+=	gtk-sharp>=0.99
BUILDLINK_PKGSRCDIR.gtk-sharp?=	../../wip/gtk-sharp
.endif	# GTK_SHARP_BUILDLINK3_MK

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libgdiplus/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/gtkhtml3/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
