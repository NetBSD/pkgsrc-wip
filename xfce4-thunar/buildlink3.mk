# $NetBSD: buildlink3.mk,v 1.1 2006/07/19 08:14:15 marttikuparinen Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_THUNAR_BUILDLINK3_MK:=	${XFCE4_THUNAR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-thunar
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-thunar}
BUILDLINK_PACKAGES+=	xfce4-thunar
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-thunar

.if ${XFCE4_THUNAR_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-thunar+=	xfce4-thunar>=0.3.2beta2
BUILDLINK_PKGSRCDIR.xfce4-thunar?=	../../wip/xfce4-thunar
.endif	# XFCE4_THUNAR_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
