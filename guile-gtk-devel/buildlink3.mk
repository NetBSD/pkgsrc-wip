# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/06/16 12:37:59 lexort Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUILE_GTK_DEVEL_BUILDLINK3_MK:=	${GUILE_GTK_DEVEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guile-gtk-devel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguile-gtk}
BUILDLINK_PACKAGES+=	guile-gtk-devel

.if !empty(GUILE_GTK_DEVEL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.guile-gtk+=	guile-gtk-devel>=0.40
BUILDLINK_PKGSRCDIR.guile-gtk?=	../../wip/guile-gtk-devel
.endif	# GUILE_GTK_DEVEL_BUILDLINK3_MK

.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
