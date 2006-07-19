# $NetBSD: buildlink3.mk,v 1.2 2006/07/19 07:29:00 marttikuparinen Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_ORAGE_BUILDLINK3_MK:=	${XFCE4_ORAGE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-orage
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-orage}
BUILDLINK_PACKAGES+=	xfce4-orage
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-orage

.if ${XFCE4_ORAGE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-orage+=	xfce4-orage>=4.3.90.2
BUILDLINK_PKGSRCDIR.xfce4-orage?=	../../wip/xfce4-orage
.endif	# XFCE4_ORAGE_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
