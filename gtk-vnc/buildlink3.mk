# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/04 16:05:28 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK_VNC_BUILDLINK3_MK:=	${GTK_VNC_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gtk-vnc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk-vnc}
BUILDLINK_PACKAGES+=	gtk-vnc
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtk-vnc

.if ${GTK_VNC_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gtk-vnc+=	gtk-vnc>=0.3.7
BUILDLINK_PKGSRCDIR.gtk-vnc?=	../../zzz/gtk-vnc
.endif	# GTK_VNC_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
