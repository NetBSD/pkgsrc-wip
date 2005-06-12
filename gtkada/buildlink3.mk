# $NetBSD: buildlink3.mk,v 1.2 2005/06/12 23:51:20 kristerw Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKADA_BUILDLINK3_MK:=	${GTKADA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GtkAda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGtkAda}
BUILDLINK_PACKAGES+=	GtkAda

.if !empty(GTKADA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.GtkAda+=	GtkAda>=2.2.1
BUILDLINK_PKGSRCDIR.GtkAda?=	../../wip/gtkada
.endif	# GTKADA_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
